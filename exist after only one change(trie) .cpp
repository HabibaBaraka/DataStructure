class MagicDictionary {
    map<string,MagicDictionary*>child;
public:
    MagicDictionary() {
        
    }
    
    void buildDict(vector<string> dic) {
        for(auto it:dic){
          
	if (!child.count(it))child[it] = new MagicDictionary;


        }
    }
    
    bool search(string s) {
        bool f = 1;
for (auto ss : child) {
	
	int cnt = 0;
	bool valid = 1;
	for (int i = 0; i <s.size(); i++) {
		if (ss.first.size() != s.size()) {
			valid = 0; break;
		}
		if (s[i] != ss.first[i]) { cnt++;  }
	}
	if(cnt==1&&valid)return 1;
}
return 0;
    }


};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */
