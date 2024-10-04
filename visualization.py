import networkx as nx
import matplotlib.pyplot as plt

# Create a graph object
G = nx.Graph()

# Add nodes (Critical Locations: Hospitals, Shelters, etc.)
nodes = {
    'Hospital': {'pos': (0, 0), 'color': 'blue'},
    'Shelter1': {'pos': (2, 1), 'color': 'green'},
    'Shelter2': {'pos': (2, -1), 'color': 'green'},
    'SupplyDepot': {'pos': (1, 2), 'color': 'orange'},
    'AffectedArea1': {'pos': (3, 2), 'color': 'red'},
    'AffectedArea2': {'pos': (3, -2), 'color': 'red'}
}

# Add nodes to the graph
for node, data in nodes.items():
    G.add_node(node, pos=data['pos'], color=data['color'])

# Add edges (roads) with weights (distances) and road status (open/blocked/optimal)
edges = [
    ('Hospital', 'Shelter1', {'weight': 5, 'status': 'open'}),
    ('Hospital', 'Shelter2', {'weight': 7, 'status': 'open'}),
    ('Hospital', 'SupplyDepot', {'weight': 8, 'status': 'optimal'}),
    ('Shelter1', 'AffectedArea1', {'weight': 10, 'status': 'blocked'}),
    ('Shelter2', 'AffectedArea2', {'weight': 12, 'status': 'blocked'}),
    ('SupplyDepot', 'AffectedArea1', {'weight': 3, 'status': 'optimal'})
]

# Add edges to the graph
for edge in edges:
    G.add_edge(edge[0], edge[1], weight=edge[2]['weight'], status=edge[2]['status'])

# Define edge colors based on road status
edge_colors = []
for u, v, data in G.edges(data=True):
    if data['status'] == 'optimal':
        edge_colors.append('blue')
    elif data['status'] == 'open':
        edge_colors.append('green')
    elif data['status'] == 'blocked':
        edge_colors.append('red')

# Get node positions and colors for visualization
pos = nx.get_node_attributes(G, 'pos')
node_colors = [data['color'] for node, data in G.nodes(data=True)]

# Draw the graph
plt.figure(figsize=(8, 6))
nx.draw(G, pos, with_labels=True, node_color=node_colors, node_size=1000, font_size=10, font_color='white', edge_color=edge_colors, width=2)

# Add labels for edge weights (distances)
edge_labels = nx.get_edge_attributes(G, 'weight')
nx.draw_networkx_edge_labels(G, pos, edge_labels=edge_labels)

# Show the plot
plt.title('Real-Time Disaster Response and Resource Allocation')
plt.show()
