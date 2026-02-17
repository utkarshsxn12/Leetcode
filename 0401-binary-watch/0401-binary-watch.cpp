class Solution {
public:
    vector<string>readBinaryWatch(int tr){
        vector<vector<string>>hh;
        hh.push_back({"0"});
        hh.push_back({"1","2","4","8"});
        hh.push_back({"3","5","9","6","10"});
        hh.push_back({"7","11"});
        vector<string>an;
        int i,j,k,m,x;
        for(i=0;i<4;i++){
            k=tr-i;
            if(k<6){
                for(j=0;j<60;j++){
                    x=__builtin_popcount(j);
                    if(x==k){
                        for(m=0;m<hh[i].size();m++){
                            string min,s=hh[i][m];
                            s=s+":";
                            min=to_string(j);
                            if(j<10) min="0"+min;
                            s=s+min;
                            an.push_back(s);
                        }
                    }
                }
            }
        }
        return an;
    }
};