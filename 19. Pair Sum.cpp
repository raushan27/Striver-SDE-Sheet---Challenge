// Pair SUM
//SDE Sheet Q19


//Brute Force Method
vector<vector<int>> pairSum(vector<int> &arr, int s){
   vector<vector<int>> res;
   vector<int> temp(2);
   
   for(int i = 0; i<arr.size(); ++i){
      for(int j  = i+1; j<arr.size(); ++j){
         if(arr[i] + arr[j] == s){
            temp[0] = min(arr[i], arr[j]);
            temp[1] = max(arr[i], arr[j]);
            res.push_back(temp);
         }
      }
   }
   sort(res.begin(), res.end());
   return res;
}

//Optimal implementation
vector<vector<int>> pairSum(vector<int> &arr, int s){
   unordered_map<int, int> mp;
   
   vector<vector<int>> res;
   vector<int> temp(2);
   
   for(auto &ele : arr){
      int count = mp[s-ele];
      while(count--){
         temp[0] = min(ele, s-ele);
         temp[1] = max(ele, s-ele);
         res.push_back(temp);
      }
      mp[ele]++;
   }
   
   sort(res.begin(), res.end());
   return res;
}
