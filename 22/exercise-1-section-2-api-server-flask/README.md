# Exercise 1 - Simple API Server in Python

Simple API server using Flask and Docker. The server will have two endpoints:

## Endpoints

1. **GET /** - Get the status of the server
2. **POST /register** - Register a new user
   - Parameters:
     - `email`: string
     - `username`: string
3. **POST /random** - Generate a random number
   - Parameters:
     - `max`: int
     - `min`: int

## Run on Local Machine

1. Clone the repository.
2. Navigate to the project directory. `cd 22/exercise-1-section-2-api-server-flask`
3. Make sure you have installed:

   - Python 3.12
   - Pipenv

     **Note** you can install them using the following commands:

     ```bash
      sudo apt update && sudo apt upgrade
      sudo apt install python3.12 pipenv
     ```

4. Install the dependencies using the following command:

   ```bash
   pipenv install
   ```

5. Run the server using the following command:

   ```bash
    pipenv run python app.py
   ```

6. Open your browser and navigate to `http://localhost:5000/` to see the server status.
7. Use Postman or any other API testing tool to test the endpoints.

## Deployment

### Build and Push Docker Image

1. Build the Docker image:

   ```bash
   docker build -t your-docker-username/your-image-name .
   ```

2. Push the Docker image to the registry:

   ```bash
   docker push your-docker-username/your-image-name
   ```

### Deploy on GCP

1. SSH into your GCP server:

   ```bash
   gcloud compute ssh your-instance-name --zone your-zone
   ```

2. Install Docker on the server:

   ```bash
   sudo apt update && sudo apt install docker.io
   sudo systemctl start docker
   sudo systemctl enable docker
   ```

3. Pull the Docker image:

   ```bash
   docker pull your-docker-username/your-image-name
   ```

4. Run the Docker container:

   ```bash
   docker run -d -p 80:5000 your-docker-username/your-image-name
   ```

5. Open your browser and navigate to `http://your-server-ip/` to see the server status.
