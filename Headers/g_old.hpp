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