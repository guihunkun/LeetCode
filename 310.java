class Solution {

/*
    *剥洋葱解法：从外层向里层进行BFS遍历
    *具体思路：
    *将图转化为邻接表存储后，若只有一条边的则为最外围的元素，将外围元素全部加入队列
    *然后在队列弹出时，需要将这个结点在邻接表中删除，层层向里，最后只剩下2个元素以内时，则为最中心元素，即以它们作为树根会得到最小高度树
    */
    public List<Integer> findMinHeightTrees(int n, int[][] edges) 
    {
        List<Integer> res = new LinkedList<Integer>();
        if(n==1) 
        {
            res.add(0);
            return res;
        }
        List[] graph = new LinkedList[n];
        for(int i=0;i<graph.length;i++)
        {//分配空间
            graph[i]=new LinkedList<Integer>();
        }
        
        for(int i=0;i<edges.length;i++)
        {//转化成邻接表存储图
            graph[edges[i][0]].add(edges[i][1]);
            graph[edges[i][1]].add(edges[i][0]);
        }
        
        boolean[] visited = new boolean[n];
        Queue<Integer> queue = new LinkedList<Integer>();
        for(int i=0;i<graph.length;i++)
        {
            if(graph[i].size()==1)
            {
                queue.offer(i);
                visited[i]=true;
            }
        }
        
        while(n>2)
        {
            int size=queue.size();
            n -= size;
            for(int i=0;i<size;i++)
            {
                int curNode = queue.poll();
                List<Integer> nodeList = graph[curNode];
                for(int j=0;j<graph.length;j++)
                {
                    if(visited[j]==true) 
                        continue;
                    else
                    {
                        graph[j].remove((Integer)curNode);
                        if(graph[j].size()==1) 
                        {
                            queue.offer(j);
                            visited[j]=true;
                        }
                    }
                    
                }
            }
        }
        
        while(!queue.isEmpty())
        {
            res.add(queue.poll());
        }
        return res;
    }
}
