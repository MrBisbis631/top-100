from flask import Flask, request
from flask_sqlalchemy import SQLAlchemy
from re import match
import random

app = Flask(__name__)
app.config['SQLALCHEMY_DATABASE_URI'] = 'sqlite:///db.sqlite'
app.config['SQLALCHEMY_TRACK_MODIFICATIONS'] = False
db = SQLAlchemy(app)


class User(db.Model):
    id = db.Column(db.Integer, primary_key=True)
    username = db.Column(db.String(50), nullable=False)
    email = db.Column(db.String(120), nullable=False)

    def toDict(self):
        return {
            "id": self.id,
            "username": self.username,
            "email": self.email
        }


with app.app_context():
    db.create_all()


@app.route('/')
def status():
    return {
        "exists": True,
        "routes": [
            {
                "path": "/",
                "method": "GET",
                "description": "Get the status of the server"
            },
            {
                "path": "/register",
                "method": "POST",
                "description": "Register a new user",
                "parameters": {
                    "username": "string",
                    "email": "string"
                }
            },
            {
                "path": "/random",
                "method": "POST",
                "description": "Generate a random number",
                "parameters": {
                    "min": "int",
                    "max": "int"
                }
            }
        ]
    }


@app.route('/register', methods=['POST'])
def register():
    user = request.json

    if 'username' not in user or 'email' not in user:
        return {"error": "username and email are required"}, 400

    if not match(r'^[a-zA-Z0-9_.+-]+@[a-zA-Z0-9-]+\.[a-zA-Z0-9-.]+$', user['email']):
        return {"error": "email is not valid"}, 400

    try:
        newUser = User(username=user['username'], email=user['email'])
        db.session.add(newUser)
        db.session.commit()
        return {'user': newUser.toDict()}, 201
    except Exception as e:
        print(e)
        return {"error": "unable to create user"}, 500


@app.route('/users')
def users():
    users = User.query.all()
    return {"users": [user.toDict() for user in users]}


@app.route('/random', methods=['POST'])
def rand():
    _range = request.json

    try:
        min_val = int(_range['min'])
        max_val = int(_range['max'])
    except KeyError:
        return {"error": "min and max are required"}, 400
    except ValueError:
        return {"error": "min and max must be integers"}, 400

    if min_val >= max_val:
        return {"error": "min must be less than max"}, 400

    random_number = random.randint(min_val, max_val)

    return {"random_number": random_number}, 200


if __name__ == '__main__':
    app.run()
