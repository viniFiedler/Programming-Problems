#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main()
{
    int testCases;
    scanf("%d", &testCases);
    while (testCases--)
    {
        int explodiu = 0;
        int corridorSize, numberOfFirecrakers, holliganPos, guardPos;
        scanf("%d %d %d %d", &corridorSize, &numberOfFirecrakers, &holliganPos, &guardPos);
        // printf("%d %d %d %d\n", corridorSize, numberOfFirecrakers, holliganPos, guardPos);
        multiset<int>
            firecrakers;

        // pega e ordena FireCrackers
        for (int i = 0; i < numberOfFirecrakers; i++)
        {
            int firecraker;
            scanf("%d", &firecraker);

            firecrakers.insert(firecraker);
        }

        // Ve qual melhor path para o ladrao
        int direcao;

        if (holliganPos > guardPos)
            direcao = 1;
        else
            direcao = -1;

        vector<int> vaiExplodir;

        // oq acontece ate o guarda estar perto demais do ladrao

        while (abs(guardPos - holliganPos) > 1)
        {
            printf("abs = %d\n", abs(guardPos - holliganPos));
            // eh sempre bom ele tacar os rojao primeiro
            vaiExplodir.push_back(*firecrakers.begin());
            firecrakers.erase(firecrakers.begin());

            // depois os rojao explode
            int tamanho = vaiExplodir.size();

            for (int i = 0; i < tamanho; i++)
            {
                // printf("Vai explodir %d\n", vaiExplodir[0]);
                vaiExplodir[i] = vaiExplodir[i] - 1;
                // printf("Vai explodir %d\n", vaiExplodir[0]);
            }

            if (vaiExplodir.size() > 0 && vaiExplodir[0] <= 0)
            {
                vaiExplodir.erase(vaiExplodir.begin());
                explodiu++;
            }

            // agora o guarda anda
            guardPos += direcao;
        }

        // depois

        if (direcao > 1)

            while (holliganPos <= corridorSize)
            {
                int tamanho = vaiExplodir.size();
                // printf("%d %d %d \n", holliganPos, tamanho, explodiu);

                for (int i = 0; i < tamanho; i++)
                {
                    // printf("Vai explodir %d\n", vaiExplodir[0]);
                    vaiExplodir[i] = vaiExplodir[i] - 1;
                    // printf("Vai explodir %d\n", vaiExplodir[0]);
                }

                if (vaiExplodir.size() > 0 && vaiExplodir[0] <= 0)
                {
                    vaiExplodir.erase(vaiExplodir.begin());
                    explodiu++;
                }

                holliganPos++;
            }
        else

        {
            int tamanho = vaiExplodir.size();
            printf("A %d | %d %d %d \n", testCases, holliganPos, tamanho, explodiu);

            for (int i = 0; i < tamanho; i++)
            {

                vaiExplodir[i] = vaiExplodir[i];
                printf("vai explodir %d\n", vaiExplodir[i]);

                if (vaiExplodir[i] <= holliganPos)
                    explodiu++;
            }
        }

        printf("B %d | %d %d \n", testCases, holliganPos, explodiu);
        cout << explodiu << endl
             << endl
             << endl;
    }

    return 0;
}