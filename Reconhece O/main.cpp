#include <iostream>
#include <random>
#include <string>
#include <stdio.h>
#include <time.h>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <math.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#define PI 3.14159265359

using namespace std;
using namespace cv;

int main (int argc, char const* argv[])
{

      int contador_o = 0;
      Mat o = cv::imread("o.png", 0);
      Mat imagem = cv::imread("desafio.png", 0);
      Mat so_o(imagem.rows, imagem.cols, CV_8UC1, Scalar(0));

      //O
      namedWindow("Com O", CV_WINDOW_AUTOSIZE);
      imshow("Com O", imagem);

      int cont_0 = 0;
      int cont_255 = 0;
      for(int i=0;i<o.rows;i++)
        {
            for (int j=0;j<o.cols;j++)
            {
                if(o.at<uchar>(i,j) == 0)
                {
                    cont_0++;
                }
                else if(o.at<uchar>(i,j) == 255)
                {
                    cont_255++;
                }
                printf("%d ",o.at<uchar>(i,j));
            }
            printf("\n");
        }

        printf("\n");
        printf("0=%d\n",cont_0);
        printf("255=%d\n",cont_255);

        for(int i=0;i<imagem.rows;i++)
        {
            for (int j=0;j<imagem.cols;j++)
            {
                int certos = 0;
                int errados = 0;
                int aux_255 = 0;
                int aux_0 = 0;

                for(int m=0;m<o.rows;m++)
                {
                    for (int n=0;n<o.cols;n++)
                    {
                        if(imagem.at<uchar>(i+m,j+n)==255)
                        {
                            aux_255++;
                        }
                        else{
                            aux_0++;
                        }

                        if(imagem.at<uchar>(i+m,j+n)==o.at<uchar>(m,n))
                        {
                            certos++;
                        }
                        else if(imagem.at<uchar>(i+m,j+n)!=o.at<uchar>(m,n))
                        {
                            errados++;
                        }
                    }
                }

                double porcentagem_certos = double(certos)/(o.cols*o.rows);
                if(porcentagem_certos>=0.91 && (aux_255>62 && aux_255<85)){
                    contador_o++;
                    printf("%d=%lf\n",contador_o,porcentagem_certos);
                    for(int m=0;m<o.rows;m++)
                    {
                        for (int n=0;n<o.cols;n++)
                        {
                            so_o.at<uchar>(i+m,j+n)=imagem.at<uchar>(i+m,j+n);
                            imagem.at<uchar>(i+m,j+n)=0;
                        }
                    }
                }
            }
        }
      namedWindow("Sem O", CV_WINDOW_AUTOSIZE);
      imshow("Sem O", imagem);
      namedWindow("So O", CV_WINDOW_AUTOSIZE);
      imshow("So O", so_o);
      waitKey(0);
      return 0;
}
