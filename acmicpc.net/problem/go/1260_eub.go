package main

import "fmt"

var N, M, V int
var edge [1001][1001]bool
var isVisited [1001]bool
var isFirst bool = true

func initialize() {
	for i := 1; i <= N; i++ {
		isVisited[i] = false
	}
	isFirst = true
}

func dfs(start int) {
	if isVisited[start] {
		return
	}
	isVisited[start] = true
	if isFirst {
		isFirst = false
	} else {
		fmt.Print(" ")
	}
	fmt.Print(start)
	for i := 1; i <= N; i++ {
		if edge[start][i] && false == isVisited[i] {
			dfs(i)
		}
	}
}

func bfs(start int) {
	queue := make([]int, 0)
	queue = append(queue, start)
	for len(queue) > 0 {
		cur := queue[0]
		queue = queue[1:]
		if isVisited[cur] {
			continue
		}
		isVisited[cur] = true
		if isFirst {
			isFirst = false
		} else {
			fmt.Print(" ")
		}
		fmt.Print(cur)
		for i := 1; i <= N; i++ {
			if edge[cur][i] && false == isVisited[i] {
				queue = append(queue, i)
			}
		}
	}

}

func main() {

	fmt.Scanln(&N, &M, &V)
	for i := 0; i < M; i++ {
		var start, end int
		fmt.Scanln(&start, &end)
		edge[start][end] = true
		edge[end][start] = true
	}
	initialize()
	dfs(V)

	fmt.Println()

	initialize()
	bfs(V)

}
