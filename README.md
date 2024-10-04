# Real-Time Disaster Response and Resource Allocation Using Graph Data Structures

## Problem Description

In natural disasters such as earthquakes, floods, or wildfires, timely and efficient resource allocation is crucial for minimizing damage and saving lives. Effective disaster response requires navigating disrupted infrastructure and adapting to rapidly changing conditions. By modeling road networks and affected areas as graphs, with nodes representing critical locations like hospitals and shelters, and edges representing roads, the system can account for real-time changes such as road closures. Utilizing **Dijkstra's Algorithm**, the system dynamically calculates optimal routes for resource delivery and transportation, ensuring an adaptive and efficient response.

## Data Structure Selection & Justification

### 1. Adjacency List (Graph)
The adjacency list will represent the road network, where nodes are critical locations (e.g., hospitals, shelters) and edges are roads with associated weights (representing travel times or conditions).

### 2. Priority Queue (Min-Heap)
Used to determine which node should be explored next in **Dijkstra's Algorithm** based on the shortest known distance. It helps to maintain the order of nodes such that the one with the smallest distance is always processed first.

### Justification
- The **Adjacency List** is essential because it holds the entire structure of the road network and supports quick access to neighbors during the pathfinding process. It ensures space efficiency for large networks and supports dynamic updates when roads are blocked or opened.
  
- The **Priority Queue** ensures that **Dijkstra’s Algorithm** efficiently finds the shortest path by always expanding the node with the minimum distance. It reduces the overall time complexity by enabling quick access to the node with the smallest distance, which is crucial for real-time decision-making in a disaster scenario.
