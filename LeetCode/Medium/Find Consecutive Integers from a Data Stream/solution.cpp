class DataStream {
public:
    vector<int> arr;
    int value;
    int k;

    int i=0;
    int j=0;
    int cnt=0;


    DataStream(int value, int k) {
        this->value = value;
        this->k = k;

    };
    
    bool consec(int num) {
        arr.push_back(num);
        if(num==value){
            cnt++;
        }

        if(j-i+1>k){
            if(arr[i]==value){
                cnt--;
            }
            i++;
        }

        j++;
     if(cnt==k){
            return true;
        }
        return false;

    
    }
   

};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */