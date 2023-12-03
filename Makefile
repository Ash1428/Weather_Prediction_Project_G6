	
menu:	
	gcc menu.c -g -o menu
	gcc Semaphore.c -g -o sem
	gcc DataInput.c -g -o input
	gcc Weatherforecast.c -g -o pred
	gcc client.c -g -o cli
	./sem
	./menu

server:
	gcc server.c -g -o ser
	./ser

clean:
	rm input menu sem pred cli ser *.txt
	
