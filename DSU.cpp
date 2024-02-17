class UnionFind
{
private:
    vi p, rank, setSize;
    int numSets;

    //initialization
    UnionFind(int N)
    {
        //the goal here is to create N singleton sets.

        p.assign(N, 0);
        //in the begining everyone is there own parent

        for(int i=0; i<N; i++){
            p[i] = i;
        }

        //the height of all trees are zero
        rank.assign(N,0);

        //the sizes of the individual sets are one
        setSize.assign(N,1);

        //the number of sets is N
        numSets = N;
    }

    int findSet(int i){
        //parent pointer points to the element itself, return
        if(p[i]==i){
            return i;
        }

        //find representative of the parent with path compression
        //by pointing the current element to the final representative
        else{
            return p[i] = findSet(p[i]);
        }
    }

    bool isSameSet(int i, int j){
        //same set if there representative is same
        return findSet(i)==findSet(j);
    }

    void unionSet(int i, int j){
        if(isSameSet(i,j)){
            return;
        }

        int x = findSet(i);
        int y = findSet(j);

        if(rank[x]>rank[y]){
            swap(x,y);
        }

        p[x] = y;

        if(rank[x] == rank[y]){
            rank[y]++;
        }

        //setsize is not accurate but will give
        //the correct answer for the representative element
        setSize[y] += setSize[x];
        numSets--;
    }

    int sizeOfSet(int i){
        return setSize[findSet(i)];
    }

    int numDisjointSets(){
        return numSets;
    }
};
