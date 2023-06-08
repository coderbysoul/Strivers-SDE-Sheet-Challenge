//https://www.codingninjas.com/codestudio/problems/search-in-a-2d-matrix_8230773?challengeSlug=striver-sde-challenge&leftPanelTab=1

bool searchMatrix(vector<vector<int>>& mat, int target) {
      int row=mat.size();
      int col=mat[0].size();

      int low=0;
      int high=row*col-1;

      while(low<=high)
      {
          int mid=(high-low)/2+low;
          int midVal=mat[mid/col][mid%col];

          if(midVal==target)
          return true;
          else if(midVal<target)
          low=mid+1;
          else
          high=mid-1;
      }  
      return false;
}