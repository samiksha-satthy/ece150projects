#include <initializer_list>
#include <iostream>
#include <cassert>

/**********************************************************************************
 * README 
 * ********************************************************************************
 * This starter code is a skeleton of the Set and Node classes.
 * You can modify this code to create your project_5 submission.
 * Any main() function or output will be ignoed by testing software.
 * A testing main() can be found on Learn.
 * 
 * From Project 5 Specification: 2.1 Development Stratigies
 * "First, implement the node class and all of its member functions. This should be
 *  straight-forward from the course notes, as they are the sam member functions as 
 *  for a linked list.
 * 
 *  Second, start with a skeleton, where each member function is defined, but where
 *  the default values of the return type is returned. ..."
 * 
 * The skeleton has been povided (below) for you to modify.
*/

class Set;
class Node;
std::ostream &operator<<( std::ostream &out, Set const &rhs );
 
  /////////////////////////////
 /// Set class declaration ///
/////////////////////////////
class Set {
  public:
    Set( std::initializer_list<int> initial_values );
   ~Set();
 
    // The instructions will describe exactly what to do
    Set( Set const &orig );
    Set( Set      &&orig );
 
    // The instructions will describe exactly what to do
    Set &operator=( Set const &orig );
    Set &operator=( Set      &&orig );
 
    // Size operations
    bool        empty() const;
    std::size_t size()  const;
 
    // Clear all items out of the set
    void clear();
 
    // Find the value item in the set
    //  - Return the address of the node if found,
    //    and nullptr otherwise.
    Node *find( int const &item ) const;
 
    // Insert the item into the set if it
    // is not already in the set.
    //  - Return 1 if the item is new,
    //    and 0 otherwise.
    std::size_t insert( int const &item );
 
    // Insert all the items in the array
    // from array[begin] to array[end - 1]
    // that are not already in the set.
    //  - Return the number of items inserted
    //    into the set.
    std::size_t insert( int         const array[],
                        std::size_t const begin,
                        std::size_t const end );
 
    // Remove the item from the set and
    // return the number of items removed.
    std::size_t erase( int const &item );
 
    // Move any items from 'other', whose values
    // do not appear in 'this', to 'this'
    // Leave any items that already appear
    // in 'this' and 'other' in 'other'. 
    std::size_t merge( Set &other );

 
    // Set operations
    Set &operator|=( Set const &other );
    Set &operator&=( Set const &other );
    Set &operator^=( Set const &other );
    Set &operator-=( Set const &other );
 
    Set operator|( Set const &other ) const;
    Set operator&( Set const &other ) const;
    Set operator^( Set const &other ) const;
    Set operator-( Set const &other ) const;
 
    // Returns 'true' if the 'other' set
    // is a subset of 'this' set; that is,
    // all entries in the 'other' set are
    // also in this set.
    bool operator<=( Set const &other ) const;
    bool operator>=( Set const &other ) const; 

    bool operator<( Set const &other ) const;
    bool operator>( Set const &other ) const;
 
    bool operator==( Set const &other ) const;
    bool operator!=( Set const &other ) const;
   
  private:
    Node *p_head_;
 
  friend std::ostream &operator<<( std::ostream &out, Set const &rhs );
};


  ///////////////////////////////
 /// Node class declaration  ///
///////////////////////////////
class Node {
  public:
    Node( int new_value, Node *new_next );
    int   value() const;
    Node *next()  const;
 
  private:
    int   value_;
    Node *next_;

  // Allow any member function in the class
  // 'Set' to access or modify the member
  // variables of any instance of this class.
  friend class Set;
};

 
  ///////////////////////////////
 /// Node class Definition   ///
///////////////////////////////

// Node constructor
Node::Node( int new_value, Node *new_next ): value_{new_value}, next_{new_next} {

}
 
int Node::value() const {
  return value_;
}

Node *Node::next() const {
  return next_;
}


  ///////////////////////////////
 /// Set class definition    ///
///////////////////////////////

// Initializing constructor
Set::Set( std::initializer_list<int> initial_values):p_head_{nullptr} {
    for (const int &val : initial_values) {
        insert(val);
    }

}

// Destructor
Set::~Set() {
    clear(); 
}

// Copy constructor
Set::Set( Set const &orig ):p_head_{nullptr} {

    for (Node *ptr{orig.p_head_}; ptr != nullptr; ptr = ptr->next()){
        insert(ptr->value()); 
    }

}

//empty
Set::Set(Set&&orig):p_head_(orig.p_head_){
    orig.p_head_ = nullptr; 
}

// assignment
Set &Set::operator=( Set const &orig ) {
  
  if (this != &orig){
    clear(); 
    for (Node * ptr{orig.p_head_}; ptr != nullptr; ptr = ptr->next())
        insert(ptr->value()); 
  }
    
  return *this; 
  
}


// Move assignment
Set &Set::operator=( Set &&orig ) {

    std::swap(p_head_, orig.p_head_); 


  return *this;
}

// Empty
bool Set::empty() const {

    if (p_head_ == nullptr){
        return true; 
    }

    else 
        return false; 

}
// Size
size_t Set::size() const {

    size_t size_{}; 

    for (Node *ptr{p_head_}; ptr != nullptr; ptr = ptr->next()){
        size_++; 
    }


  return size_;
}

// Clear
void Set::clear() {

    while (p_head_ != nullptr){
        Node* tmp = p_head_; 
        p_head_ = p_head_ -> next(); 
        delete tmp; 
        
    }

    p_head_ = nullptr; 

}

// Find
Node *Set::find( int const &item ) const { 

    for (Node *ptr{p_head_}; ptr != nullptr; ptr = ptr->next()){

        if (ptr -> value() == item){

            return ptr; 
        }

    }

    return nullptr;
}

// Insert the item into the set
std::size_t Set::insert( int const &item ) {

    if (find(item) != nullptr){
        return 0; 
    }

    Node *new_space = new Node (item, p_head_); 
    p_head_ = new_space; 
    return 1;  

    

}
 
// Insert all the items in the array
std::size_t Set::insert( int    const array[],
                         std::size_t const begin,
                         std::size_t const end ) {


    std::size_t inserted_count{}; 


    for (std::size_t i = begin; i < end; i++){

        if (insert(array[i]) == 1){
            inserted_count++; 
        }
    }

  return inserted_count;
}

// Remove the item from the set and
// return the number of items removed.
std::size_t Set::erase( int const &item ) {

    Node *prev = nullptr; 
    Node *current = p_head_; 

    while (current != nullptr){
        if (current->value() == item){
            if(!prev){
                p_head_ = current->next(); 
            }
            else{
                prev->next_ = current->next(); 
            }

            delete current;
            return 1; 
        }

        prev = current;
        current = current->next(); 
    }

  return 0;
}


// Move any items from 'other', whose values
// do not appear in 'this', to 'this'.
// Leave any items that already appear
// in both sets, in both sets. 
std::size_t Set::merge( Set &other ) {
    std::size_t number{}; 
    Node *cur = other.p_head_;
    Node *prev = nullptr; 
    while (cur != nullptr){
        if (find(cur->value()) == nullptr){
            if(prev == nullptr)
                other.p_head_ = cur->next(); 
            else
                prev->next_ = cur->next(); 
            cur->next_ = p_head_;
            p_head_ = cur; 
            if(prev == nullptr)
                cur = other.p_head_; 
            else   
                cur = prev->next(); 
            number++;   
        }
        else {
            prev=cur; 
            cur=cur->next(); 
        }
    }

    return number; 
}
 

  //////////////////////
 /// Set operations ///
//////////////////////
Set &Set::operator|=( Set const &other ) {
    for (Node*ptr{other.p_head_}; ptr != nullptr; ptr = ptr->next_){
        insert(ptr->value()); 
    }

    return *this; 
}
 
Set &Set::operator&=( Set const &other ) {
    Node *prev = nullptr; 
    Node *current = p_head_; 
    while (current != nullptr){
        if (other.find(current->value()) == nullptr){
            Node *to_delete = current; 
            if (prev == nullptr){
                p_head_ = current->next(); 
            }
            else{
                prev->next_ = current->next(); 
            }

            current = current -> next_; 
            delete to_delete; 
        }else{
            prev = current;
            current = current->next();
        }

    }

    return *this; 

}
 
Set &Set::operator^=( Set const &other ) {
    for (Node *ptr{other.p_head_}; ptr != nullptr; ptr = ptr->next()){
        if (find(ptr->value()) != nullptr){
            erase(ptr->value()); 
        }

        else{
            insert(ptr->value()); 
        }
        
    }

    return *this; 

}
 
Set &Set::operator-=( Set const &other ) {
  for (Node *ptr {other.p_head_}; ptr != nullptr; ptr = ptr->next()){
    erase(ptr->value()); 
  }

  return *this; 
}
 
Set Set::operator|( Set const &other ) const {
  Set tmp{*this}; 
  tmp |= other; 
  return tmp; 
}
 
Set Set::operator&( Set const &other ) const {
  Set tmp{*this}; 
  tmp &= other; 
  return tmp; 
}
 
Set Set::operator^( Set const &other ) const {
  Set tmp{*this}; 
  tmp ^= other; 
  return tmp;
}
 
Set Set::operator-( Set const &other ) const {
  Set tmp{*this}; 
  tmp -= other; 
  return tmp; 
}
 
// Returns 'true' if the 'other' set
// is a subset of 'this' set; that is,
// all entries in the 'other' set are
// also in this set.
bool Set::operator<=( Set const &other ) const {

    return other>= *this; 

}

bool Set::operator>=( Set const &other ) const {

for (Node *ptr{other.p_head_}; ptr != nullptr; ptr = ptr->next()){
    if (find(ptr->value()) == nullptr){
        return false; 
    }
}

return true; 


}
 
 bool Set::operator<( Set const &other ) const {
  if (size() >= other.size()){
    return false; 
  }
  
  else
    return other > *this;
}

bool Set::operator>( Set const &other ) const {


    if (size() <= other.size())
        return false;

    else 
        return operator>=(other); 
    
}
 
 
bool Set::operator==( Set const &other ) const {
 
 if (operator>=(other) == true && operator<=(other) == true){
    return true; 
 }
 
 else
    return false;
}
 
bool Set::operator!=( Set const &other ) const {
  if (operator>=(other) == true && operator<=(other) == true){
    return false; 
  }

  else 
    return true; 
}


  ////////////////////////////////////////////
 /// Supplied Code for print Set objects  ///
////////////////////////////////////////////
/// @brief Overloads the << operator allowing the print of Set objects
/// @param out The ostream to print to (e.g. std::cout <<)
/// @param rhs The Set to print (e.g. << set_A)
/// @note You do not need to edit or alter this code
std::ostream &operator<<( std::ostream &out, Set const &rhs ) {
  out << "{";
  if ( !rhs.empty() ) {
    out << rhs.p_head_->value();   
    for ( Node *ptr{ rhs.p_head_->next() }; ptr != nullptr; ptr = ptr->next() ) {
      out << ", " << ptr->value();
    }
  }
  out << "}";
 
  return out;
}


int main (){

  Set A{};
  A.insert( 1 );
  A.insert( 2 );
  A.insert( 3 );
 
  Set B{2,3,4};
  Set C{3,3,4,4,4,5,5,5,5};

  std::cout << std::endl << "--- Set initialization / insert ---" << std::endl;
  std::cout << "A: " << A << std::endl;  // {1,2,3}
  std::cout << "B: " << B << std::endl;  // {2,3,4}
  std::cout << "C: " << C << std::endl;  // {3,4,5}

  std::cout << std::endl << "--- size / empty ---" << std::endl;
  std::cout << "size of A:  " << A.size()  << std::endl; // 3
  std::cout << "is A empty: " << A.empty() << std::endl; // 0 (false)

  assert(A.find(3) != nullptr);
  assert(A.find(4) == nullptr);

  std::cout << std::endl << "--- erase / instert ---" << std::endl;
  std::cout << "erase 3: " << A.erase(3) << std::endl; // 1
  std::cout << "erase 3: " << A.erase(3) << std::endl; // 0
  std::cout << "A:       " << A << std::endl;          // {1,2}

  int insert_values[5]{1,2,3,4,5};
  std::cout << "insert [1,2,3]: " << A.insert(insert_values, 0, 3) << std::endl; // 1
  std::cout << "A:       " << A << std::endl;   // {1,2,3}

  std::cout << std::endl << "--- Copy constructor / clear ---" << std::endl;
  Set *D { new Set {A} };
  std::cout << "A:       " <<  A << std::endl;  // {1,2,3}
  std::cout << "B:       " <<  B << std::endl;  // {2,3,4}
  std::cout << "D:       " << *D << std::endl;  // {1,2,3}
  *D = B;
  std::cout << "D = B:   " << *D << std::endl;  // {2,3,4}
  D->clear();
  std::cout << "D clear: " << *D << std::endl;  // {}
  assert(D->empty() == true);
  delete D;
  D = nullptr;

  // Set operations
  std::cout << std::endl << "--- Set Operations ---" << std::endl;
  std::cout << "A union B: " << ( A | B ) << std::endl;
  std::cout << "A intersect B: " << ( A & B ) << std::endl;
  std::cout << "Symmetric difference of A and B: " << ( A ^ B ) << std::endl;
  std::cout << "A minus B: " << ( A - B ) << std::endl;
  std::cout << std::endl;

  std::cout << "A union C: " << ( A | C ) << std::endl;
  std::cout << "A intersect C: " << ( A & C ) << std::endl;
  std::cout << "Symmetric difference of A and C: " << ( A ^ C ) << std::endl;
  std::cout << "A minus C: " << ( A - C ) << std::endl;
  std::cout << std::endl;
 
  std::cout << "B union C: " << ( B | C ) << std::endl;
  std::cout << "B intersect C: " << ( B & C ) << std::endl;
  std::cout << "Symmetric difference of B and C: " << ( B ^ C ) << std::endl;
  std::cout << "B minus C: " << ( B - C ) << std::endl;
  std::cout << std::endl;
 
/* Expected output from set operations: 
    --- Set Operations ---
    A union B: {4, 1, 2, 3}
    A intersect B: {2, 3}
    Symmetric difference of A and B: {4, 1}
    A minus B: {1}

    A union C: {4, 5, 1, 2, 3}
    A intersect C: {3}
    Symmetric difference of A and C: {4, 5, 1, 2}
    A minus C: {1, 2}

    B union C: {5, 2, 3, 4}
    B intersect C: {3, 4}
    Symmetric difference of B and C: {5, 2}
    B minus C: {2}
*/

  return 0;

}