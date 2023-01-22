// template <class TV, class TE>
// class IncList{
//     private:
//         IMap<Vertex<TV>, LinkedListSequence<Edge<TE>>>* map;
//     public:

//         IncList(){map=nullptr;}

//         IncList(IMap<Vertex<TV>, LinkedListSequence<TE>>* map){
//             this->map = map;
//         }

//         void Add(const Pair<TV, TE>& pair){
//             map->Add(pair);
//         }

// };
// template<class TV, class TE>
// class OrGrapgh{
//     private:
//         IncList<TV, TE> inclist;

//     public:
//         // OrGrapgh(IMap<Vertex<TV>, LinkedListSequence<Edge<TE>>>* map) : inclist(map) {}
//         OrGrapgh();

//         void Add(Pair<TV, TE> pair){
//             inclist->Add(pair);
//         }
// };

// template<class TV, class TE>
// class Graph{
//     private:
//         IMap<Vertex<TV>, LinkedListSequence<Edge<TE>>>* map;

//     public:
//         Graph(){}
//         ~Graph(){delete map;}
//         //Copying constructor;


// //       // OrGrapgh(IMap<Vertex<TV>, LinkedListSequence<Edge<TE>>>* map) : inclist(map) {}
//         Graph(int(*cmp)(const Pair<Vertex<TV>, LinkedListSequence<Edge<TE>>>&, const Pair<Vertex<TV>, LinkedListSequence<Edge<TE>>>&)){
//             map = new AVLMap<Vertex<TV>, LinkedListSequence<Edge<TE>>>(cmp);
//         }

//         void AddSingleVertex(const Vertex<TV>& vertex){
//             LinkedListSequence<Edge<TE>> clearlist;
//             map->Add(vertex, clearlist);
//         }

//         void AddEdge(int vertexId, const Edge<TE>& edge){
//             Vertex<TV> vertex(vertexId);
//             map->Get(vertex).Append(edge);
//         }

//         void Add(Pair<TV, TE> pair){
//             map->Add(pair);
//         }

//         Sequence<int>* GetVertexesIds() const {
//             Sequence<Vertex<TV>>* vertexes = map->GetKeys();
//             Sequence<int>* vertexesIds = new ArraySequence<int>();
            
//             for (int i = 0; i < vertexes->GetLength(); i++){
//                 vertexesIds->Append(vertexes->Get(i).GetId());
//             }

//             delete vertexes;
//             return vertexesIds;
//         }

//         LinkedListSequence<Edge<TE>>& GetEdges(int vertexId) const {
//             Vertex<TV> vertex(vertexId);
//             return map->Get(vertex);
//         }
// };




/////////DEKSTRA

// void init (int Vert){
    // for 
// }
// Sequence<int>* s;
// Sequence<int>* p;
// Sequence<bool>* used;
// // int s[] = {}
// // int d[] = {}; // расстояния 
// const int INF = 1000000;

// void Dijkstra(int vertexesQty, int vertexStartId){

//     s = new ArraySequence<int>();
//     p = new ArraySequence<int>();
//     used = new ArraySequence<bool>();
//     //INIT:
//     for (int i = 0; i < vertexesQty; i++){
//         s->Append(INF);
//         p->Append(-1);
//         used->Append(false);
//     }
//     s->Set(vertexStartId, 0);
//     p->Set(vertexStartId, vertexStartId);
//     //ALGO:

//     for (int i = 0; i < vertexesQty; i++){
//         int v = -1;
//         for (int j = 0; j < vertexesQty; j++){
//            if (!(used->Get(j)) && (v == -1 || (s->Get(j) < s->Get(v)))){
//                 v = j;
//            } 

//            if (s->Get(v) == INF) break;
//            used->Set(v, true);
//            //смежные вершины
//            //

//         }
//     }


// Sequence<int>* dist;
// Sequence<int>* p;
// Sequence<bool>* use;

// void  Dekstra(int vertexesQty, int vertexStartId, const Graph<int,int>& graph) {
//     dist = new ArraySequence<int>();
//     use = new ArraySequence<bool>();

//     for (int i = 0; i < vertexesQty; i++){
//         dist->Append(INF);
//         use->Append(false);
//     }

//     dist->Set(vertexStartId, 0);

//     for (int i = 0; i < vertexesQty; i++){
//         v = -1;
//         for (int j = 0; j < vertexesQty; j++){
//             if (!(use->Get(j)) && v==-1 || (dist->Get(j) < dist->Get(v)));
//                 v = j;
//         }
//         if (dist->Get(v) == INF) break;
//         use->Set(v, true);
        
        
//         Sequence<int>* adjVertexes = graph.GetAdjVert
//     }


// }