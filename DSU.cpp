class UnionFind
{
private:
    vll p, rank, setSize, maxSet, minSet;
    vll sumSet;
    ll numSets;

public:
    // initialization
    UnionFind(ll N)
    {
        // the goal here is to create N singleton sets.

        p.assign(N, 0);
        // in the begining everyone is there own parent

        for (ll i = 0; i < N; i++)
        {
            p[i] = i;
        }

        // the height of all trees are zero
        rank.assign(N, 0);

        // the sizes of the individual sets are one
        setSize.assign(N, 1);

        // the number of sets is N
        numSets = N;

        maxSet.assign(N, INT_MIN);
        minSet.assign(N, INT_MAX);
        sumSet.assign(N, 0);
    }

    ll findSet(ll i)
    {
        // parent pointer points to the element itself, return
        if (p[i] == i)
        {
            maxSet[i] = max(maxSet[i], i);
            minSet[i] = min(minSet[i], i);
            return i;
        }

        // find representative of the parent with path compression
        // by pointing the current element to the final representative
        else
        {
            return p[i] = findSet(p[i]);
        }
    }

    bool isSameSet(ll i, ll j)
    {
        // same set if there representative is same
        return findSet(i) == findSet(j);
    }

    void unionSet(ll i, ll j)
    {
        if (isSameSet(i, j))
        {
            return;
        }

        ll x = findSet(i);
        ll y = findSet(j);

        if (rank[x] > rank[y])
        {
            swap(x, y);
        }

        p[x] = y;

        if (rank[x] == rank[y])
        {
            rank[y]++;
        }

        // setsize is not accurate but will give
        // the correct answer for the representative element
        setSize[y] += setSize[x];
        sumSet[y] += sumSet[x];
        maxSet[y] = max(maxSet[y], maxSet[x]);
        minSet[y] = min(minSet[y], minSet[x]);
        numSets--;
    }

    ll sizeOfSet(ll i)
    {
        return setSize[findSet(i)];
    }

    ll numDisjointSets(){
        return numSets;
    }

    ll maxInSet(ll i)
    {
        return maxSet[findSet(i)];
    }

    ll minInSet(ll i)
    {
        return minSet[findSet(i)];
    }

    void makeSet(ll i, ll x){
        p[i] = i;
        rank[i] = 0;
        sumSet[i] = x;
        numSets += 1;
        setSize[i] = 1;
    }

    ll sumOfSet(ll i){
        return sumSet[findSet(i)];
    }
};
