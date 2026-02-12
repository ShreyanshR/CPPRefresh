#include <iostream>
#include <memory>

class Resource {
public:
  Resource() { std::cout << "Resource Acquired" << std::endl; }
  ~Resource() { std::cout << "Resource Released" << std::endl; }
};

void process(std::unique_ptr<Resource> rPtr) {
  std::cout << "Processing Resource\n";
}
/*
unique ptr can be used to manange resources within a class, to dynamically
allocate members within class
Smart Pointers are used to allocated memory on Heap, so be careful when u want
to allocate memory to Stack
*/

class Widget {
private:
  std::unique_ptr<Resource> resource;

public:
  Widget() : resource(std::make_unique<Resource>()) {}
};

class Node {
public:
  std::unique_ptr<Node> left;
  std::unique_ptr<Node> right;
};

class TreeNode {
public:
  std::shared_ptr<TreeNode> left;
  std::shared_ptr<TreeNode> right;

  TreeNode() { std::cout << "Tree Node Created" << std::endl; }
  ~TreeNode() { std::cout << "Tree Node destroyed" << std::endl; }
};

int main() {
  auto resourcePtr = std::make_unique<Resource>();
  process(std::move(resourcePtr)); // this have move the rPtr, so it doesn't
                                   // exist, as the resoruce is freed

  if (!resourcePtr)
    std::cout << "rPtr is now null" << std::endl;

  std::shared_ptr<Resource> res1 = std::make_shared<Resource>();
  std::cout << "Ref count: " << res1.use_count() << std::endl;
  {
    std::shared_ptr<Resource> res2 = res1;
    std::cout << "Insdie inner block" << std::endl;
    std::cout << "Ref count: " << res1.use_count() << std::endl;
  }

  std::cout << "Ref count: " << res1.use_count() << std::endl;

  auto root = std::make_shared<TreeNode>();
  root->left = std::make_shared<TreeNode>();
  root->right = std::make_shared<TreeNode>();

  return 0;
}