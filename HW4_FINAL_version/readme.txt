this is final version

for part A, linked list is a build-in structure which will be used in part B and part C, thus we don't need to test it for now. But I write two functions for them, called "testlinkedlist.c". 


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
for part B, the way to compile it:

     gcc -o hwhw part_b_main.c part_b_main_support_2.c LinkedList.c board.c
     ./hwhw
    
then, the result will appear in the terminal, which includes the color "player" went through and how many steps he takes

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
for part C, the way to complie it:
    gcc -o hwhw player_2.c part_b_main_support_2.c LinkedList.c board.c
    ./hwhw


then, the result includes:
who wins the game, 
his name,
the color he went through;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
