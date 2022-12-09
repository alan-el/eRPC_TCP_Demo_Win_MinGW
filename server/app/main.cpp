#include "erpc_matrix_multiply_server.h"
#include "erpc_server_setup.h"
#include "erpc_transport_setup.h" /* Not eRPC file. Need be replaced with include of transport type. */

#include <cstdio>

/* implementation of function call */
void erpcMatrixMultiply(Matrix matrix1, Matrix matrix2, Matrix result_matrix)
{
    /* code for multiplication of matrices */
    for (int i = 0; i < matrix_size; i++)
    {
        for (int j = 0; j < matrix_size; j++)
        {
            int sum = 0;
            for(int k = 0; k < matrix_size; k++)
                sum += matrix1[i][k] * matrix2[k][j];

            result_matrix[i][j] = sum;
        }
    }
}

int main()
{
    /* Init eRPC server environment */
    /* UART transport layer initialization */
    erpc_transport_t transport = erpc_transport_tcp_init("127.0.0.1", 5047, true);

    /* MessageBufferFactory initialization */
    erpc_mbf_t message_buffer_factory = erpc_mbf_dynamic_init();

    /* eRPC server side initialization */
    erpc_server_init(transport, message_buffer_factory);

    /* connect generated service into server, look into erpc_matrix_multiply_server.h */
    erpc_service_t service = create_MatrixMultiplyService_service();
    erpc_add_service_to_server(service);

    /* run server */
    erpc_server_run(); /* or erpc_server_poll(); */

    return 0;
}
