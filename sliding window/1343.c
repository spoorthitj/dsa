int numOfSubarrays(int* arr, int arrSize, int k, int threshold) {
  
        int sum=0;
        for(int i=0;i<k;i++){
              sum+=arr[i];
        }
    
        int count=0;
        if(sum/k>=threshold){
count++;
            }
        int l=0;
        for(int i=k;i<arrSize;i++){
             sum=sum+arr[i]-arr[l];
            l++;
            if(sum/k>=threshold){
count++;
            }
           
        }
   return count; }  
