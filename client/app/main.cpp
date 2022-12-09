#include "erpc_matrix_multiply.h"
#include "erpc_client_setup.h"
#include "erpc_transport_setup.h" /* Not an eRPC file. Needs to be replaced with the included transport type. */

#include <cstdio>

int main()
{
    /* Matrices definitions */
    Matrix matrix1, matrix2, result_matrix = {{0}};

    /* Init eRPC client environment */
    /* UART transport layer initialization */
    erpc_transport_t transport = erpc_transport_tcp_init("127.0.0.1", 5047, false); /* DEMO_UART defined in fsl_uart_cmsis.h */

    /* MessageBufferFactory initialization */
    erpc_mbf_t message_buffer_factory = erpc_mbf_dynamic_init();

    /* eRPC client side initialization */
    erpc_client_init(transport, message_buffer_factory);

    /* other code like init matrix1 and matrix2 values */
    for (int i = 0; i < matrix_size; i++)
    {
        for (int j = 0; j < matrix_size; j++)
        {
            matrix1[i][j] = matrix2[i][j] = matrix_size * i + j;
        }
    }

    /* call eRPC functions */
    erpcMatrixMultiply(matrix1, matrix2, result_matrix);

    /* other code like print result matrix */
    for (int i = 0; i < matrix_size; i++)
    {
        for (int j = 0; j < matrix_size; j++)
        {
            printf("%5d ", result_matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
