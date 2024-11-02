

run: # run container
	bash scripts/run_container.sh

test: #run test
	make -C tests/googletest/
	./tests/googletest/test.out
	pytest tests/pytest
