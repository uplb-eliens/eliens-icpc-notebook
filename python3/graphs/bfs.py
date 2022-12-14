from input_graph import graph 

def bfs(graph, start):
    visited, queue = set(), [start]
    while queue:
        vertex = queue.pop(0)
        if vertex not in visited:
            visited.add(vertex)
            queue.extend(graph[vertex] - visited)
    return visited

print(bfs(graph, 'A')) # {'B', 'C', 'A', 'F', 'D', 'E'}
