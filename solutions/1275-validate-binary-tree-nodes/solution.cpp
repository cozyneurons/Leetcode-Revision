class Solution {
public:
    vector<int> parent;
    int compo;
    int find(int node)
    {
        if (parent[node]==node) return node;
        return parent[node] = find(parent[node]);
    }
    bool Union (int C, int P)
    {
        if (find(P)==C) return false;
        if (find(C)!=C) return false;
        parent[C] = P;
        compo--;
        return true;
    }
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) 
    {
        compo = n;
        parent.resize(n);
        for (int i = 0; i<n; i++)
        {
            parent[i] = i;
        }
        for (int i = 0; i<n; i++)
        {
            if (leftChild[i]!=-1 && Union(leftChild[i],i)==false) return false;
            if (rightChild[i]!=-1 && Union(rightChild[i],i)==false) return false;
        }
        return compo==1;
   }
};
