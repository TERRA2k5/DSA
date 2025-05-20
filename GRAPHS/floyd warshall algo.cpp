// dist is a adjency matrix
// this algo uses brute by checking all possible ways

void floydWarshall(vector<vector<int>> &dist) {
    int n = dist.size();


    // if not reachable are marked with -1 then make it 1e8
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < n ; j++){
    //         if(dist[i][j] == -1){
    //             dist[i][j] = 1e8;
    //         }
    //     }
    // }

    
    // check path via all nodes
    for(int via = 0; via < n ; via++){

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n ; j++){
                if(dist[i][via] != 1e8 && dist[via][j] != 1e8 && dist[i][j] > dist[i][via] + dist[via][j]){
                    dist[i][j] = dist[i][via] + dist[via][j];
                }
            }
        }
    }


    // check negative cycle 
    for (int i = 0; i < n; ++i)
    {
        if(dist[i][i] < 0){
            // return for negative cycle
            return;
        }
    }

    // reverse marking 1e8 back to -1
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < n ; j++){
    //         if(dist[i][j] == 1e8){
    //             dist[i][j] = -1;
    //         }
    //     }
    // }
}