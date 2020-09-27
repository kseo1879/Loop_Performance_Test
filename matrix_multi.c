#include <stdio.h>
#include <stdlib.h>

void multiply1(const float* mata, size_t mata_width, size_t mata_height, 
    const float* matb, size_t matb_width, size_t matb_height,
    float** result_mat, size_t* res_width, size_t* res_height) {

    if(result_mat) {
        *res_width = matb_width;
        *res_height = mata_height;
        *result_mat = calloc(mata_height * matb_width, sizeof(float));

        for(size_t y = 0; y < mata_height; y++) { 
            for(size_t x = 0; x < matb_width; x++) {
                for(size_t k = 0; k < mata_width; k++) { 
                    (*result_mat)[(y * matb_width) + x] +=
                        (mata[(y * mata_width) + k] * 
                        matb[(k * matb_width) + x]);
                }
            }
        }
    }
}

void multiply2(const float* mata, size_t mata_width, size_t mata_height, 
    const float* matb, size_t matb_width, size_t matb_height,
    float** result_mat, size_t* res_width, size_t* res_height) {

    if(result_mat) {
        *res_width = matb_width;
        *res_height = mata_height;
        *result_mat = calloc(mata_height * matb_width, sizeof(float));

        float r = 0;
        for(size_t x = 0; x < mata_width; x++) { 
            for(size_t k = 0; k < mata_width; k++) {
                r = mata[(x * mata_width) + k];
                for(size_t y = 0; y < mata_width; y++) { 
                    (*result_mat)[(x * matb_height) + y] += 
                    r * matb[(k * mata_height) + y];
                }
            }
        }
    }
}

void multiply3(const float* mata, size_t mata_width, size_t mata_height, 
    const float* matb, size_t matb_width, size_t matb_height,
    float** result_mat, size_t* res_width, size_t* res_height) {

    if(result_mat) {
        *res_width = matb_width;
        *res_height = mata_height;
        *result_mat = calloc(mata_height * matb_width, sizeof(float));

        float r = 0;
        for(size_t x = 0; x < mata_width; x++) { 
            for(size_t k = 0; k < mata_width; k++) {
                r = mata[(x * mata_width) + k];
                for(size_t y = 0; y < mata_width; y += 8) { 
                    (*result_mat)[(x * matb_height) + y] += 
                    r * matb[(k * mata_height) + y];

                    (*result_mat)[(x * matb_height) + y + 1] += 
                    r * matb[(k * mata_height) + y + 1];

                    (*result_mat)[(x * matb_height) + y + 2] += 
                    r * matb[(k * mata_height) + y + 2];

                    (*result_mat)[(x * matb_height) + y + 3] += 
                    r * matb[(k * mata_height) + y + 3];

                    (*result_mat)[(x * matb_height) + y + 4] += 
                    r * matb[(k * mata_height) + y + 4];

                    (*result_mat)[(x * matb_height) + y + 5] += 
                    r * matb[(k * mata_height) + y + 5];

                    (*result_mat)[(x * matb_height) + y + 6] += 
                    r * matb[(k * mata_height) + y+ 6];

                    (*result_mat)[(x * matb_height) + y + 7] += 
                    r * matb[(k * mata_height) + y+ 7];
                }
            }
        }
    }
}

void multiply4(const float* mata, size_t mata_width, size_t mata_height, 
    const float* matb, size_t matb_width, size_t matb_height,
    float** result_mat, size_t* res_width, size_t* res_height) {

    if(result_mat) {
        *res_width = matb_width;
        *res_height = mata_height;
        *result_mat = calloc(mata_height * matb_width, sizeof(float));

        float r = 0;
        for(size_t x = 0; x < mata_width; x++) { 
            for(size_t k = 0; k < mata_width; k++) {
                r = mata[(x * mata_width) + k];
                for(size_t y = 0; y < mata_width; y += 4) { 
                    (*result_mat)[(x * matb_height) + y] += 
                    r * matb[(k * mata_height) + y];

                    (*result_mat)[(x * matb_height) + y + 1] += 
                    r * matb[(k * mata_height) + y + 1];

                    (*result_mat)[(x * matb_height) + y + 2] += 
                    r * matb[(k * mata_height) + y + 2];

                    (*result_mat)[(x * matb_height) + y + 3] += 
                    r * matb[(k * mata_height) + y + 3];
                }
            }
        }
    }
}

/**
 * The main function will recieve the size of the input as the command line. 
 * time ./matric_multi 20 20 20 20 
 * First argument after the name of the time would be mata_width, than
 * mata-height, matb_witdh, and matb_height. 
 */

int main(int argc, char **argv) {
    //It should exactly get five argument. 
    if(argc == 5) {
        size_t mata_width = atoi(argv[1]);
        size_t mata_height = atoi(argv[2]); 
        size_t matb_width = atoi(argv[3]);
        size_t matb_height = atoi(argv[4]);

        float *mata = malloc(sizeof(float) * mata_width * mata_height);
        float *matb = malloc(sizeof(float) * matb_width * matb_height);

        //This will assign integer value that is below 100 to mata
        for(int i = 0; i < mata_width; i ++) {
            for(int j = 0; j < mata_height; j++) {
                mata[i * mata_width + j] = rand() % 100;
            }
        }

        //This will assign integer value that is elow 100 to matb
        for(int i = 0; i < mata_width; i ++) {
            for(int j = 0; j < mata_height; j++) {
                matb[i * matb_width + j] = rand() % 100;
            }
        }

        size_t res_width = 0;
        size_t res_height = 0;
        float* result_mat;


        multiply1(mata, mata_width, mata_height, matb, matb_width,
            matb_height, &result_mat, &res_width, &res_height);

        free(result_mat);
        free(mata);
        free(matb);
    }

    return 0;
}
