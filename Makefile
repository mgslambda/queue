q_peek_q_offer_test: src/queue.c test/q_peek_q_offer_test.c
	mkdir -p bin
	gcc -o bin/q_peek_q_offer_test src/queue.c test/q_peek_q_offer_test.c

q_poll_test: src/queue.c test/q_poll_test.c
	mkdir -p bin
	gcc -o bin/q_poll_test src/queue.c test/q_poll_test.c
