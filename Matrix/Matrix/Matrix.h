#ifndef matrix_h
#define matrix_h
class matrix{
public:
    int **a;
    int col;
    int row;
    matrix(){}
    matrix(char c){
        cout<<"Please input the col of "<<c<<'\n';
        cin>>col;
        cout<<"Please input the row of "<<c<<'\n';
        cin>>row;
        a= new int *[row];
        for(int i=0;i<row;++i){
            a[i]=new int[col];
        }
        cout<<"Please input the matrix\n";
        for(int i=0;i<row;++i)
            for(int j=0;j<col;++j){
                cin>>a[i][j];
            }
    }
    matrix(int x,int y){
        row=x;
        col=y;
        a= new int *[x];
        for(int i=0;i<x;++i){
            a[i]=new int[y];
        }
    }
    void show(){
        for(int i=0;i<row;++i)
        {
            for(int j=0;j<col;++j){
                cout<<a[i][j]<<' ';
            }
            cout<<endl;
        }
    }
    matrix operator+(matrix x){
        matrix c(row,col);
        for(int i=0;i<row;++i)
            for(int j=0;j<col;++j){
                c.a[i][j]=a[i][j]+x.a[i][j];
            }
        return c;
    }
    matrix operator-(matrix x){
        matrix c(row,col);
        for(int i=0;i<row;++i)
            for(int j=0;j<col;++j){
                c.a[i][j]=a[i][j]-x.a[i][j];
            }
        return c;
    }
    matrix operator*(matrix x){
        matrix c(row,col);
        for(int i=0;i<row;++i)
            for(int j=0;j<col;++j){
                int sum=0;
                for(int k=0;k<col;++k)
                    sum+=a[i][k]*x.a[k][j];
                c.a[i][j]=sum;
            }
        return c;
    }
};
#endif
