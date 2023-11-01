![Screenshot from 2023-11-01 15-46-17](https://github.com/reomelo/42Porto-push_swap/assets/73884501/cd2ce691-9e92-4c46-9d84-998a0c30b4af)

### Description of the project:
Push_swap is a program that sorts a stack of integers with the minimum instructions possible and an auxiliary stack. Instructions are defined within the subject of the project; They're the only way allowed to manipulate the data in the stacks.

checker is a utility program that, taking the same arguments as push_swap and its outputted instructions, checks if the stack ends up sorted, thus verifying if push_swap is correctly sorting the stack.

### Installing and running the project:
1- Clone this repository and enter it:  

	git clone https://github.com/reomelo/42Porto-push_swap.git && cd 42Porto-push_swap

2- Run `make` and execute with a list of integers (read subject):

	make && ./push_swap <nbr> <nbr> <nbr> ...

### Makefile Available Targets:  
`make` or `make all` - compiles the project      
`make clean` - wipes all object files   
`make fclean` - deletes ./push_swap and all object files   
`make re` - fclean  + all

___
######  At [42School](https://en.wikipedia.org/wiki/42_(school)), almost every project must be written in accordance to the [Norm](https://github.com/42School/norminette). As a result, parts of the code are not as clean, efficient or straight forward as they could be.
