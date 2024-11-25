#include <map>
#include <string>
#include <vector>

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        std::unordered_map<std::string, std::vector<std::string>> mp;
        std::vector<std::vector<std::string>> ans;

        // init map with sorted
        std::for_each(strs.begin(), strs.end(), [&](auto str)
                      {
            auto sorted_str{str};
            std::sort(sorted_str.begin(), sorted_str.end());
            mp[sorted_str].push_back(str); });

        return std::accumulate(mp.begin(), mp.end(),
                               std::vector<std::vector<std::string>>(),
                               [](auto res, auto item)
                               {
                                   res.push_back(item.second);
                                   return res;
                               });
    }
};
