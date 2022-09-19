class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        vector<vector<string>> res;
        int l = paths.size();
        unordered_map<string,vector<string>> mp;
        for(auto path:paths){
            stringstream sst(path);
            string dir, file;
            getline(sst, dir,' ');
            while(getline(sst,file,' ')){
                string filename = dir + '/' + file.substr(0,file.find('('));
                string filecontent = file.substr(file.find('(') + 1 , file.find('(') -file.find(')') - 1);
                mp[filecontent].push_back(filename);
            }
        }
        for(auto entry: mp)
            if(entry.second.size()>1)res.push_back(entry.second);
        
        return res;
    }
};
