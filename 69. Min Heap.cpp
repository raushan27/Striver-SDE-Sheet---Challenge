// Min Heap
// SDE Sheet Q69

vector<int> minHeap(int n, vector<vector<int>> &q)
{
    vector<int> ans;
    vector<int> temp;

    auto mini = temp.begin();

    for (int i = 0; i < n; i++)
    {
        if (q[i][0] == 0)
        {
            temp.push_back(q[i][1]);
            mini = min_element(temp.begin(), end(temp));
        }
        else
        {
            ans.push_back(*mini);
            temp.erase(mini);
        }
    }
    return ans;
}