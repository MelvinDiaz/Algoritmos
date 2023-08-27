    int a, b, aux;

    while (scanf("%d %d", &a, &b), (a != 0 || b != 0))
    {
        int cont = 0;
        unordered_set<int> n, m;
        while (a != 0)
        {
            scanf("%d", &aux);
            n.insert(aux);
            a--;
        }
        while (b != 0)
        {
            scanf("%d", &aux);
            m.insert(aux);
            b--;
        }
        if (n.size() < m.size())
        {
            for (auto i : n)
            {
                if (auto search = m.find(i); search == m.end())
                {
                    cont++;
                }
            }
        }