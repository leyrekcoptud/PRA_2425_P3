bin/testTableEntry: testTableEntry.cpp TableEntry.h
	mkdir -p bin
	g++ -o bin/testTableEntry testTableEntry.cpp

clean:
	rm -rf *.o *.gch bin

bin/testHashTable: Dict.h HashTable.h TableEntry.h testHashTable.cpp 
	mkdir -p bin
	g++ -o bin/testHashTable testHashTable.cpp

bin/testBSTree: BSTree.h BSNode.h testBSTree.cpp
	mkdir -p bin
	g++ -o bin/testBSTree testBSTree.cpp

bin/testBSTreeDict: Dict.h BSTreeDict.h BSNode.h TableEntry.h testBSTreeDict.cpp 
	mkdir -p bin
	g++ -o bin/testBSTreeDict testBSTreeDict.cpp
