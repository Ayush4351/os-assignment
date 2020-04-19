#include <stdio.h> 
int main() 
{ 

	int n, m, i, j, k; 
	n = 5; // n is the Number of processes which has to be executed
	m = 3; // m is the Number of resources which are available
	
	// Resource Allocation Table 
	int alloc[5][3] = { { 0, 1, 0 }, // P0 (Process 0)
						{ 2, 0, 0 }, // P1 (Process 1)
						{ 3, 0, 2 }, // P2 (Process 2)
						{ 2, 1, 1 }, // P3 (Process 3)
						{ 0, 0, 2 } }; // P4 (Process 4)

	// Max Resource required table 
	int max[5][3] = { { 7, 5, 3 }, // P0 (Process 0)
					{ 3, 2, 2 }, // P1 (Process 0)
					{ 9, 0, 2 }, // P2 (Process 0)
					{ 2, 2, 2 }, // P3 (Process 0)
					{ 4, 3, 3 } }; // P4 (Process 0)

	// Available Resources
	int avail[3] = { 3, 3, 2 };  

	
	int f[n];
	int ans[n]; 
	int ind = 0; 
	for (k = 0; k < n; k++) { 
		f[k] = 0; 
	} 
	int need[n][m]; 
	for (i = 0; i < n; i++) { 
		for (j = 0; j < m; j++) 
			need[i][j] = max[i][j] - alloc[i][j]; 
	} 
	int y = 0; 
	for (k = 0; k < 5; k++) { 
		for (i = 0; i < n; i++) { 
			if (f[i] == 0) { 

				int flag = 0; 
				for (j = 0; j < m; j++) { 
					if (need[i][j] > avail[j]){ 
						flag = 1; 
						break; 
					} 
				} 

				if (flag == 0) { 
					ans[ind++] = i; 
					for (y = 0; y < m; y++) 
						avail[y] += alloc[i][y]; 
					f[i] = 1; 
				} 
			} 
		} 
	} 

	//Here is the output of Safe sequence
	printf("Following is the SAFE Sequence of above process execution\n"); 
    for (i = 0; i < n - 1; i++) 
        printf(" P%d ->", ans[i]); 
    printf(" P%d", ans[n - 1]); 
  
    return (0);
} 

