/* Given two integers, n and m. The task is to check the relation between n and m.

Examples :

Input: n = 4, m = 8
Output: lesser
Explanation: 4 < 8 so print 'lesser'.
Input: n = 8, m = 8
Output: equal
Explanation: 8 = 8 so print 'equal'.
*/

  public:
    string compareNM(int n, int m){
        if(n < m){
            return "lesser";
        } else if(n == m){
            return "equal";
        } else {
            return "greater";
        }
    }
};