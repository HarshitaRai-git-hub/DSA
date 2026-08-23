class Solution {
public:
    bool sumGame(string num) {
        int suml=0;
        int sumr=0;
        int a=0,b=0;
        for(int i=0;i<num.size();i++){
            if(i<num.size()/2){
                if(num[i]=='?')a++;
                else suml+=(num[i]-'0');
            }else{
                if(num[i]=='?')b++;
                else sumr+=(num[i]-'0');
            }
        }
         if((a + b) % 2 != 0)
            return true;

        return (suml - sumr) * 2 != (b - a) * 9;
    }
};