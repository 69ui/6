#include <stdio.h>
#include <limits.h>
#define MAX 10 // Maximum number of cities
// Function to find the minimum cost of the TSP and the path taken
int tsp(int graph[][MAX], int pos, int visited, int cost, int start, int V, int path[], int *pathIndex) 
{
 if (visited == (1 << V) - 1) { // If all cities have been visited
 path[*pathIndex] = start; // Add starting city to complete the cycle
 (*pathIndex)++;
 return cost + graph[pos][start]; // Return to the starting city
 }
 int minCost = INT_MAX;
int bestCity = -1;
 for (int city = 0; city < V; city++) {
 if ((visited & (1 << city)) == 0) { // If the city has not been visited yet
 int newVisited = visited | (1 << city);
 int newCost = cost + graph[pos][city];
 int tspCost = tsp(graph, city, newVisited, newCost, start, V, path, pathIndex);
 if (tspCost < minCost) {
 minCost = tspCost;
 bestCity = city;
 }
 }
 }
 // Add the best city to the path
 path[*pathIndex] = bestCity;
 (*pathIndex)++;
 return minCost;
}
int main() {
 int V;
 // Input the number of cities
 printf("Enter the number of cities: ");
 scanf("%d", &V);
 if (V > MAX) {
printf("Number of cities exceeds the maximum limit of %d\n", MAX);
 return 1;
 }
 int graph[MAX][MAX];
 // Input the distances between cities
 printf("Enter the distances between the cities in matrix form:\n");
 for (int i = 0; i < V; i++) {
 for (int j = 0; j < V; j++) {
 printf("Distance from city %d to city %d: ", i + 1, j + 1);
 scanf("%d", &graph[i][j]);
 }
 }
 int start = 0; // Starting city
 int visited = 1 << start; // Mark the starting city as visited
 int path[MAX + 1]; // To store the path (extra space for returning to the start)
 int pathIndex = 0; // Path index
 path[pathIndex++] = start; // Start from the first city
 int result = tsp(graph, start, visited, 0, start, V, path, &pathIndex);
 printf("The minimum cost of the TSP is: %d\n", result);
 printf("The path taken is: ");
 for (int i = 0; i < pathIndex; i++) {
 printf("%d ", path[i] + 1); // Print the path (adjusting for 1-based indexing)
 }
 printf("\n");
Return 0;
}