class Solution {
public:
    int bitwiseComplement(int N) {
        int sum = 0;
        long pow=1;
		// Do, while is used because if N is 0, then it has to add 1 and not go directly out of the loop.
        do{
            if(N%2==0) sum+=pow;
            N = (N>>1);
            pow*=2;
        }while(N);
        return sum;
    }
};
