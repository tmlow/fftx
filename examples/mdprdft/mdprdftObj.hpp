using namespace fftx;

// static constexpr auto mdprdft_script{
//     R"(szhalfcube := DropLast(szcube,1)::[Int(Last(szcube)/2)+1];
//     var_1:= var("var_1", BoxND([0,0,0], TReal));
//     var_2:= var("var_2", BoxND(szcube, TReal));
//     var_3:= var("var_3", BoxND(szhalfcube, TReal));
//     var_2:= X;
//     var_3:= Y;
//     symvar := var("sym", TPtr(TReal));
//     transform := TFCall(TDecl(TDAG([
//            TDAGNode(TTensorI(MDPRDFT(szcube,sign),1,APar, APar), var_3,var_2),
//                   ]),
//             [var_1]
//             ),
//         rec(fname:=name, params:= [symvar])
//     );
//     )"
// };

std::string mdprdft_script = "szhalfcube := DropLast(szcube,1)::[Int(Last(szcube)/2)+1];\n\
    var_1:= var(\"var_1\", BoxND([0,0,0], TReal));\n\
    var_2:= var(\"var_2\", BoxND(szcube, TReal));\n\
    var_3:= var(\"var_3\", BoxND(szhalfcube, TReal));\n\
    var_2:= X;\n\
    var_3:= Y;\n\
    symvar := var(\"sym\", TPtr(TReal));\n\
    transform := TFCall(TDecl(TDAG([\n\
           TDAGNode(TTensorI(IMDPRDFT(szcube,sign),1,APar, APar), var_3,var_2),\n\
                  ]),\n\
            [var_1]\n\
            ),\n\
        rec(fname:=name, params:= [symvar])\n\
    );";


class MDPRDFTProblem: public FFTXProblem {
public:
    using FFTXProblem::FFTXProblem;
    void randomProblemInstance() {
    }
    void semantics() {
        std::cout << "szcube := [" << sizes.at(0) << ", " << sizes.at(1) << ", " << sizes.at(2) << "];" << std::endl;
        std::cout << "sign := -1;" << std::endl;
        std::cout << "name := \""<< name << "_spiral" << "\";" << std::endl;
        std::cout << mdprdft_script << std::endl;
    }
};
