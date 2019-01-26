import java.util.*;

public class Dikjstra {
	private static int[][] graph;
	private static int vertNumb;
	private static int start;

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		System.out.println("Dikjstra's shortest path algorithm.");
		System.out.println("Do you want to proceed? Y/N");
		String ans = input.nextLine();
		while((ans.toUpperCase()).equals("Y") == false && (ans.toUpperCase()).equals("N") == false){
			System.out.println("\""+ans+"\"" + ": incorrect command");
			System.out.println("Try Again. \nEnter \"Y/y\" for Yes, or \"N/n\" for No");
			System.out.println("Do you want to proceed? Y/N");
			ans = input.nextLine();
		}
		if (ans.toUpperCase().equals("N")){
			System.out.println("Program has stopped.");
			System.exit(0);
		}
		else if (ans.toUpperCase().equals("Y")) {
			boolean run = true;
			while (run) {
				try {
					readData();
					dijkstra(start);
					System.out.println("\nDo you want to try another test? Y/N");
					ans = input.nextLine();
					if (ans.toUpperCase().equals("Y"))
						run = true;
					if (ans.toUpperCase().equals("N")) {
						System.out.println("Program has stopped.");
						run = false;
					}
				} catch (Exception e) {
					System.out.println(e.getMessage());
				}
			}
		}
	}
	//Reads user's input
	private static void readData() throws Exception {
		Scanner scan = new Scanner(System.in);
		try {
			System.out.println("Enter the number of vertices");
			vertNumb = scan.nextInt();
			graph = new int[vertNumb][vertNumb];
			System.out.println("Enter the Weighted Matrix for the graph");
			for (int i = 0; i < vertNumb; i++) {
				for (int j = 0; j < vertNumb; j++) {
					graph[i][j] = scan.nextInt();
				}
			}
			System.out.println("Enter the source ");
			start = scan.nextInt();
		} catch (InputMismatchException e) {
			throw new Exception("\nWrong Input");
		}
	}
	//Dikjstra's Algorithm
	private static void dijkstra(int start) {
		boolean[] marked = new boolean[vertNumb];
		int[] dist = new int[vertNumb], prev = new int[vertNumb];
		//Initialization
		for (int i = 0; i < vertNumb; i++) {
			dist[i] = Integer.MAX_VALUE;
			marked[i] = false;
			prev[i] = -1;
		}
		dist[start - 1] = 0;
		// Algorithm
		for (int count = 0; count < vertNumb - 1; count++) {
			int u = minDistance(dist, marked);
			marked[u] = true;

			for (int v = 0; v < vertNumb; v++)
				if (!marked[v] && graph[u][v] != 0 && dist[u] != Integer.MAX_VALUE && dist[u] + graph[u][v] < dist[v]) {
					dist[v] = dist[u] + graph[u][v];
					prev[v] = u;
				}
		}
		// printing the path and distance of each node
		for (int i = 0; i < vertNumb; i++) {
			if (dist[i] == Integer.MAX_VALUE) {
				System.out.printf("There is no path from Vert%d to Vert%d", start, i + 1);
				System.out.println("");
			} else {
				System.out.printf("\nDistance from Vert%d to Vert%d equals %d", start, i + 1, dist[i]);
				System.out.printf("\nPath: Vert%d", start);
				path(prev, i);
				System.out.println("");
			}
		}
	}
	//Finds the vertex with minimum distance, return vertex
	private static int minDistance(int dist[], boolean marked[]) {

		int min = Integer.MAX_VALUE, min_index = -1;

		for (int i = 0; i < vertNumb; i++)
			if (marked[i] == false && dist[i] <= min) {
				min = dist[i];
				min_index = i;
			}
		return min_index;
	}
	//Prints path
	private static void path(int[] prev, int i) {
		if (prev[i] == -1)
			return;
		path(prev, prev[i]);
		System.out.printf(" -> Vert%d", i + 1);
	}
}
