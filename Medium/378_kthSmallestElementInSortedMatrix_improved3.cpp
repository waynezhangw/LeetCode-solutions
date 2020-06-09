class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        unsigned int n=matrix[0].size();
    	int MIN=matrix[0][0];
        int MAX=matrix[n-1][n-1];
        map<int,int> myMatrix;
        map<int,int> uniqueID;
        vector<int> smallToBig;
        pair<map<int,int>::iterator, bool> Insert_Pair;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                Insert_Pair=uniqueID.insert(pair<int,int>(matrix[i][j],0));   
            }
        }


        for(int i=0;i<MAX-MIN+1;i++)          //因为受这个MAX-MIN的限制，如果这个太大那就炸了
        {
            if(uniqueID.count(MIN+i)==0)
            {
                continue;
            }
            Insert_Pair=myMatrix.insert(pair<int,int>(MIN+i,0));   
            if(Insert_Pair.second==false)               
            {
                cout<<"impossible!!!"<<endl; 
            }
            else
            {
                smallToBig.push_back(MIN+i);
            }                      
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                Insert_Pair=myMatrix.insert(pair<int,int>(matrix[i][j],0));   
                if(Insert_Pair.second==false)               
                {
                    myMatrix[matrix[i][j]]++;
                } 
            }
        }

        int tempSum=0;
        for(int i=0;i<myMatrix.size();i++)
        {
            tempSum=tempSum+myMatrix[smallToBig[i]];
            if(tempSum>=k)
            {
                return smallToBig[i];
            }                               
        }

        return 0;
    }
};