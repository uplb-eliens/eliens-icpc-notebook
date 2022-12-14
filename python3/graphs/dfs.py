from input_graph import graph

def dfs(graph, start):
    visited, stack = set(), [start]
    while stack:
        vertex = stack.pop()
        if vertex not in visited:
            visited.add(vertex)
            stack.extend(graph[vertex] - visited)
    return visited

print(dfs(graph, 'A')) # {'E', 'D', 'F', 'A', 'C', 'B'}
