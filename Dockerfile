# import compiler to a docker directory
FROM gcc:latest
WORKDIR /app
COPY . /app


# run and compile
RUN g++ -o file1 link_list_bank.cpp
CMD ["./file1"]
