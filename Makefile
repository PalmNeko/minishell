

run: # run container
	bash scripts/run_container.sh

down:
	docker container stop minishell

test: test_gtest test_pytest test_norm # run test

test_gtest:
	make -C tests/googletest/
	valgrind -q --leak-check=full --error-exitcode=12 ./tests/googletest/test.out

test_pytest:
	bash tests/pytest/run_test.sh

test_norm:
	! (norminette src | grep -v OK) && echo "Norminette OK" || false
