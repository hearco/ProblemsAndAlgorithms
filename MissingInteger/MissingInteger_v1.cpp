#include <set>
#include <iterator>

int solution(vector<int> &A)
{
    set<int> ordered;
    for(auto i = A.begin(); i != A.end(); ++i)
    {
        if(*i > 0)
        {
            ordered.insert(*i);
        }
    }
    
    if(!ordered.empty())
    {
        set<int>::iterator itr;
        int i = 1;
        for(itr = ordered.begin(); itr != ordered.end(); ++itr)
        {
            if(i != *itr)
            {
                return i;
            }
            i++;
        }
    }
    else
    {
        return 1;
    }
}
