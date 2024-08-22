class Solution {
public:
    int findComplement(int num) {
        long temp = num;
        int msb = 0;
        while(temp){
            msb++;
            temp = temp>>1;
        }
        long bit = 1;
        cout<<msb<<endl;
        return num^((bit<<msb) - 1);
        return 0;
    }
};