class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) 
    {
        unsigned int n=matrix[0].size();
    	int low=matrix[0][0];
        int high=matrix[n-1][n-1];
        while(low<=high)
        {
        	double middle=low+double(high-low)/2.0;
        	int lessNum=getLessEqualNum(matrix,middle);
        	if(lessNum<k)
        	{
        		low=int(middle)+1;
        	}
        	else
        	{
        		high=int(middle)-1;
        	}
        }
        return low;
    }

    int getLessEqualNum(vector<vector<int>>& matrix, double mid)
    {
    	unsigned int n=matrix[0].size();
    	int sum=0;
    	int i=n-1;
    	int j=0;
    	while(i>=0 && j<n)
    	{
    		if(matrix[i][j]<=mid)    //因为假如到最后一个数，不小于等于就永远到不了最大
    		{
    			sum=sum+i+1;
    			j++;
    		}
    		else
    		{
    			i--;
    		}
    	}
    	return sum;
    }
};