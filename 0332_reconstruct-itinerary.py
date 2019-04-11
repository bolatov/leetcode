from collections import deque, namedtuple
from itertools import islice
class Solution:
    def findItinerary(self, tickets: List[List[str]]) -> List[str]:
        g = {}
        for src, dst in tickets:
            g.setdefault(src, []).append(dst)
        for src, dsts in g.items():
            g[src] = deque(sorted(dsts, reverse=True))
        # do DFS
        State = namedtuple('State', 'graph airport path')
        stack = deque([State(g, 'JFK', [])])
        while stack:
            t = stack.pop()
            t.path.append(t.airport)
            if len(t.path) == len(tickets) + 1:
                return t.path
            nxt_ports = t.graph.get(t.airport, [])
            for i, nxt_port in enumerate(nxt_ports):
                nxt_graph = {}
                for src, dsts in t.graph.items():
                    if src == t.airport:
                        dsts = deque(islice(dsts, 0, i)) + deque(islice(dsts, i+1, len(dsts)))
                    if len(dsts) > 0:
                        nxt_graph[src] = dsts
                nxt_state = State(nxt_graph, nxt_port, t.path[:])
                stack.append(nxt_state)
        return []
        
