#include <bits/stdc++.h>
using namespace std;

// Function to check if brackets are balanced
string areBracketsBalanced(string _userString) {
	stack<char> brackets; // Declare a character stack that we will use to check the string for balanced brackets.
  stack<int> indices; // Declare an integer stack that we will use to keep track of the string indices of our brackets.
  
	for (int i = 0; i < _userString.length(); i++) {
		  if (brackets.empty()) {
        if(_userString[i] == '(' || _userString[i] == '{' || _userString[i] == '[') {
          brackets.push(_userString[i]); // If the brackets stack is empty, and the current character is an opening bracket, push it to the brackets stack.
          indices.push(i); // Push the string index of the character we've just pushed to the indices stack, so we can store it for later if needed.
        }
        else if (_userString[i] == ')' || _userString[i] == '}' || _userString[i] == ']')
          return to_string(++i); // If the brackets stack is empty and we are attempting to push a closing bracket, it is unmatched. Return its 1-based string index.
		  }  
		  else if ((brackets.top() == '(' && _userString[i] == ')') || (brackets.top() == '{' && _userString[i] == '}') || (brackets.top() == '[' && _userString[i] == ']')) {
        brackets.pop(); // If we find a matched set of brackets, pop the opening bracket from the brackets stack, as it has been matched to a closing bracket in the string.
        indices.pop(); // Pop the bracket's corresponding string index from the indices stack.
		  }
		  else {
        if(_userString[i] == '(' || _userString[i] == '{' || _userString[i] == '[') {
          brackets.push(_userString[i]); // If we haven't found a matching pair and the current character is an opening bracket, push it to the brackets stack.
          indices.push(i); // Push the index of the character we've just pushed to the indices stack, so we can store it for later if needed.
        } 
        else if(_userString[i] == ')' || _userString[i] == '}' || _userString[i] == ']')
          return to_string(++i); // If the unmatched character is a closing racket, return its 1-based string index, as it is the first unmatched closing bracket.
		  } 
	}
  
	if (brackets.empty()) {
		return "Success"; // After iterating through every character in the string, if the stack is empty, every set of brackets has been matched, and the string is balanced.
	}
  else { // If the stack is not empty after iterating through the string, there is an unmatched opening bracket. We must return its index.
    while(!brackets.empty()) {
      brackets.pop();  // While the brackets list is not empty, pop an element from the brackets list.
      if(!brackets.empty()) // If the brackets list is still not empty, pop an element from the indices list.
        indices.pop();
      else // If the brackets list is now empty after the latest pop, it was the first unmatched opening bracket in the string.
        return to_string(indices.top() + 1); // Return the 1-based index of the first unmatched opening bracket in the string.
    }
  }
  
	return "An error has occurred."; // If this return statement is ever reached, there has been an error.
}

int main(void) {
	string _userString = "";
  cout << areBracketsBalanced(_userString) << endl;

  // Test statements from assignment outline.
  cout << areBracketsBalanced("[]") << endl;
  cout << areBracketsBalanced("{}[]") << endl;
  cout << areBracketsBalanced("[()]") << endl;
  cout << areBracketsBalanced("(())") << endl;
  cout << areBracketsBalanced("{[]}()") << endl;
  cout << areBracketsBalanced("{") << endl;
  cout << areBracketsBalanced("{[}") << endl;
  cout << areBracketsBalanced("foo(bar);") << endl;
  cout << areBracketsBalanced("foo(bar[i);") << endl;

  // Test statements from "test.zip" file.
  cout << areBracketsBalanced("[]") << endl;
  cout << areBracketsBalanced("()") << endl;
  cout << areBracketsBalanced("{}") << endl;
  cout << areBracketsBalanced("{}[]") << endl;
  cout << areBracketsBalanced("{}()") << endl;
  cout << areBracketsBalanced("[]()") << endl;
  cout << areBracketsBalanced("[][]") << endl;
  cout << areBracketsBalanced("[()]") << endl;
  cout << areBracketsBalanced("(())") << endl;
  cout << areBracketsBalanced("{{}}") << endl;
  cout << areBracketsBalanced("{}[]{}") << endl;
  cout << areBracketsBalanced("{[]}()") << endl;
  cout << areBracketsBalanced("[{{}}]") << endl;
  cout << areBracketsBalanced("{") << endl;
  cout << areBracketsBalanced("}") << endl;
  cout << areBracketsBalanced("[") << endl;
  cout << areBracketsBalanced("]") << endl;
  cout << areBracketsBalanced("(") << endl;
  cout << areBracketsBalanced(")") << endl;
  cout << areBracketsBalanced("}()") << endl;
  cout << areBracketsBalanced("{[}") << endl;
  cout << areBracketsBalanced("[)]") << endl;
  cout << areBracketsBalanced("(){[}") << endl;
  cout << areBracketsBalanced("{}{}]") << endl;
  cout << areBracketsBalanced("[]({)") << endl;
  cout << areBracketsBalanced("[](()") << endl;
  cout << areBracketsBalanced("(({})") << endl;
  cout << areBracketsBalanced("({})}") << endl;
  cout << areBracketsBalanced("[{}]{") << endl;
  cout << areBracketsBalanced("()[{}])") << endl;
  cout << areBracketsBalanced("[[]}]{}") << endl;
  cout << areBracketsBalanced("({()(})") << endl;
  cout << areBracketsBalanced("[]](") << endl;
  cout << areBracketsBalanced("{[}]") << endl;
  cout << areBracketsBalanced("[}]]") << endl;
  cout << areBracketsBalanced("][]]") << endl;
  cout << areBracketsBalanced("{[])") << endl;
  cout << areBracketsBalanced("(}{}") << endl;
  cout << areBracketsBalanced("({(}") << endl;
  cout << areBracketsBalanced("[({])}") << endl;
  cout << areBracketsBalanced("ablabla)ihihi(ohoho") << endl;
  cout << areBracketsBalanced("[very(strong]test)") << endl;
  cout << areBracketsBalanced("({})[()](){}[]{}{[{}]}{}(())([]){[]}()(())[]{}{}[][]{}[][{}]{}(){}[](({})){}()[{[{}]}]([])[](){}()[()]{}[]()()[][]{}[()]()[]()(){}[]{}[][]{}()()[](){}{}()[]{}()()()[]{}()()(){}[]()(())([])()[][]()([])[]{}{[]}[]()()({})[{}](())(){()}{()}{[]}{}()[()][]()()[]({})[]{}{}(){}()()[]()[]{{}}{}[][][]()[{}][]{}[]()[][]()[()]([{}])[[()]]{()}{}({{}})()(()){}(){}(){}([])(){()}{}[][]([()])[]{}{[]}[][](()){}([[]])({})(){}[](){[]}[](){}{()}[]{}{[]}[]{[()]}[{}][{}]{({})}()(())()[([])]({}){}{()}{([])}({()}){{{[]}}}[{}](){}{}(){}()[]([])(){}()[](){}()[][][](())[][(())]([]){[]}([()]){}[](){}(){()}{}[][](){}()({})({})(){{[]}}[{}]{}[{}][]({})[[()]]{}{[]}{}[]{[]}{{}}()(){()}{}[][[]][][{[{}]}]{[]}()()([{}]){}[]([{}])[][]([]){}[{}][]()(){}{()}()([])[()]{}[][{{[]}}]{()}(){}()({})[]{[(())]}[]{}[({[]})][[]]{}(){()}()(()){}[]{[]}[][]{}{}[](){}{}[]()[][]{}{}(){[]}(){}()[[]]{}(){([])}{[{}]}()[()][][]({}){}[][]{[]}(){[]}{{}}{}{}{}[{}]{}([]){}{}()()[()][{}][]({[]})[]()[]()()()[][]({[]})([])([])[](())()[{{}}]{}()[[]]()()[]{}[]{}{}[][][](()){}{}{}[]{}{}({}){{}}(([]))[]()(){}{()}[([])](){}{()}[]()()[]()[](){}{[]}[]{}{}[]()()[]()[]{}(){}()()[](({}))[]()[]()()([{}])()(([]))()[[]][]{}[](){}[{}]{}[([])]{}([])(){()}(){}(){{}}{}{}[][][{}](){()}()([[]]){()}[][[]][[{}]]{{}}[{}]{}{}(){()}()(){[]}()[[]]{[()]}[]{}()[]({})[](){}[]()()[[]][[]]()()()()()()[]{}[]({})[](){{}}{}[]()[]{}{{}}[]{}({}){}({()})[]{{}}{()}{}{}[{}](){}([])()()[]{}[]{}[]{}[]({{}})([]){}[()]()[][](){}()[]()()()([]){()}()([]){}()[()]{}()[][]()(())[]{{}}{}[][]()[]()()[]{}[][[]]()[][[]][][][[]][][]{}[]{(())}()[](){[]}()[{}]{}{}()[]{}()()()[][][][][][]({})[][]()[]{()}{}[][](){}[]{}{}[{(())}]{}{[{[]}]}[{()}](){[[]]}[[]]{{}}{([])}[{[]}]()({()})[]()({[]})()[[[]]]{{}}[(())][[({[]})]]{{[]}}{[[[]]]}{()}{{}}[()]{}{()}[]{}{}(){}()[[]]{{}}[{}][]{([])}[()](){}[[]]{}{[[]]}(({}))[][([])]{}[][]{{}}[[{}]]{{{}}}{{[]}}(())[]{()}()[][()]({}){}[{}]()[](())[](){}[{}]{}(){{()}}{}()[][()][[()]]{}(){}[{}]()(())()[{()}]{}([{}])()[]({})()(())[](){()}{}[]()([])[{}]{}[{}]()") << endl;
  cout << areBracketsBalanced("{{[[{{(({{{()}}}))}}]]}}[{[{{}}]}]([([{{[{[{[{(({{({({{{[[[{[[[{[[{[[{{[[{([({[([({[{[((([[{[[{({(([(({({[{[[{[({{[([[(({{[[{[([({([([[([{[[[{{{{[({([({{{[([({{[[(({(([({[[([{(([[{([[{({{{[[([{{[{{({{(([{[([[{[[([[([[([[{({{[{({((([([{{[{{({{[[([[((((({((([{[{[({([{[{([{([{([[[[(({{{[[[([({[({{[[({[({{[((((({{([[{[((((({[{{{([([{[[(([({[[[[({{([([{[{{{({{{({{{({({[{(([{(([(([[[(({({([(([{({{{((([((([[{{(([({([{((((([[[(({([[({({[(({{[({[[{({{[(({[([[{([{({([[[([[[[((({([[[([{(([({[[{([{{[{[{([({{(([(({[[({[{([{[{[({[[({{{{[{((({})))}]}}}})]]})]}]}])}]})]]}))]))}})])}]}]}}])}]]})]))}])]]])})))]]]])]]])})}])}]])]}))]}})}]]})]}}))]})})]])}))]]])))))}])})]))}}]])))])))}}})}]))])})}))]]]))]))}]))}]})})}}})}}})}}}]}])])}})]]]]})]))]]}])])}}}]})))))]}]])}})))))]}})]})]]}})]})])]]]}}}))]]]])}])}])}]}])})]}]}])))})))))]])]]}})}}]}}])])))})}]}})}]])]])]])]]}]])]}]))}})}}]}}])]]}}})}]])}]]))}])]]})]))}))]]}})])]}}})])})]}}}}]]]}])]])])})])]}]]}}))]])]}})]}]]}]})}))]))})}]]}]])))]}]})])]})])}]]}}]]}]]}]]]}]]]}}})})}}))}]}]}]}}])])[[[]]](){{{[((([({(([{[{{[[{[{{[([({{{[{([[{[{(((({{{({({[[[[{{{({{{[[{({{[[{[[[[({([([[(({{[[({[{[([{[[{[{{[{{[([{{([[[[(({[[{({(([([[{[(([({})]))]}]])]))})}]]}))]]]])}}])]}}]}}]}]]}])]}]})]]}}))]])])})]]]]}]]}})}]]}}})}}}]]]]})})}}}))))}]}]])}]}}})])]}}]}]]}}]}]))})])))]}}}{({{[({})]}})}{[{[[{({{[[()]]}})}]]}]}{()}([{[]}]){}{}(){{}}{{}}[][][][()][]{}[]()[]{}(([((([({[({({})})]})])))]))[]{([{(({{{{[[[{{([[]])}}]]]}}}}))}])}[[[]]]{}[{{{(())}}}][]()[][([[{[([[{({[([[{([{[{[([{{([([{(([{{[[[[[(((((({[{{([{{{{({{{[[((({[([[[{([[{[{{(({[[[({[(({[[{(([[{{[{}]}}]]))}]]}))]})]]]}))}}]}]])}]]])]})))]]}}})}}}}])}}]}))))))]]]]]}}]))}])])}}])]}]}])}]])]})}]])]}]])][({[[([[[{{{([[[{[([([[{(((([(([[[()]]]))]))))}]])])]}]]])}}}]]])]]})]{}([[([{{[{{{()}}}]}}])]])[{}]([[]]){}{}{((((([{{}}])))))}[[]][{[()]}][{([([{{{[{}]}}}])])}]([[[()]]]){}()[()][]{}{}[{}]()[{}][](())(([[[]]]))(){}((([]))){}([])(){}(){}(){}[{(())}]()()[]{{}}{[([{}])]}{}[](){}{(())}[[({})]]()[{}][](())") << endl;
  cout << areBracketsBalanced("(([({{((({([[({{((((({(({{[[({([{[({[{({{[[[[({{(([([({({({([([[[[{{{[{({[{({([{{{[([{{{{({[(([{{({[(({(([(({[[([{[[(([({[{([(([[{([[{{([[{[({[([{[[({[[((([({[[[([({[{({([{{{(({[({{((({[{[[{[{{[{([{{[([{(({(({{{({{[([{{{{({{({[({[{({{{{({{[{[{(({[({[{({([([{[{({{[([{[(({{[{({((({([({{[[[({{[[[[[([[[([[[{[[{{[([[{[([{{{({{[{[{({[({[([{[{[{{[({({{([{([([[[[[{({{[({(([[[({[{[{[{({[{((([(({{[{([[({{({([(({{[{{(([{[{((((((((([{{([({[([{({([{{({{[{{[{(([[{(({{([([{[[{([{[({[{({[({[[[(({([[(({{[[{[[(({(({{{[{[[[[[[{[{{{{[(([([{[[{{[[([[(([[[{{([(([{(({{{{[[(([[[{{[([[{(({(([({{[[[([({[{{[[[(([{([(({[((([[([(({{{[{(([[{{{[([(([[({[[[({[((([[({{({{{[(({(([[([([([[([([{[[[[[(([[(({{(((([[({{{({{({([([{{[[[({([{[[([{([({{[[[{{([{[{({({[{((([{{(([[[{[({{({([{[{({(({(((((([({{{{[{({[{[{[{{({{{[[(([[([{([[((({{({(((([{[{{[{{({[[({[[[[[{{{((({{([{([{(([{(({[[({[[[({{[([{{([([{({{[({{[[[{([([[({({[[[[[{{({{[{{[{[[[[{([(([({(({{[({[[({([{([{(((({[(((([{([{{({{[({{[(({[(({[((([[[(([{{((([{([({{{((([({(())})])))}}})])}])))}}]))]]])))]}))]}))]}})]}})}}])}]))))]}))))}])}])})]]})]}}))})]))])}]]]]}]}}]}})}}]]]]]})})]])])}]]]}})]}})}])])}}])]}})]]]})]]}))}]))}])}])}})))}}}]]]]]})]]})}}]}}]}]))))})}})))]])}])]]))]]}}})}}]}]}]})}]}}}})]))))))}))})}]}])})}})]}]]]))}}])))}]})})}]}])}}]]]}})])}])]]}])})]]]}}])])})}})}}})]]))))}}))]]))]]]]]}])])]])])])]]))}))]}}})}})]])))]})]]]})]]))])]}}}]]))}]}}}))])]])))]}))])}]))]]]}}]})])]]]}})]))}))}]])]}}]]]))]]}}}}))}]))])}}]]]))]])]]}}]]}])]))]}}}}]}]]]]]]}]}}}))}))]]}]]}}))]])}))]]]})]})}]})]}])}]]}])])}}))}]]))}]}}]}})}}])})}])]})])}}])))))))))}]}]))}}]}}))])})}})]])}]}}))])))}]})}]}]}]})]]]))})]}})}]]]]])])}])}})})]}}]}]}])]})]})}]}]}})}}}])]}]])]}}]]}]]])]]])]]]]]}})]]]}})])})))})}]}}))]}])]}})}]}])])})}]})]}))}]}]}})}}}})}]})]})}})}}}}])]}})}}}))}))}])]}}])}]}}]}]]}]})))}})]}))}}}])})}]})])]]]})])))]]})]]}])]})]}]])}}]])}]]))])}]})]))]]}])]]}))]))}))]})}}]))]})}}}}])]}}}])})}]})}]}}}]]]])])})})})])]))}})]]]]}})}]})]}])})]]}}))})))))}})]])})))}})]))") << endl;
  cout << areBracketsBalanced("X{89}{w}(gy)b?r(;)[CS[e]Ko]5{eMi}[n(;);J](o)ls{}a(5NW(RA)m)BA.[][N(V()ka)1x]()()BS{w.}r[?j(7F)Zw](v)G;[B[U]L][]{Y}d([ud])I[Z];(V)[7I(w(W)lF)Q]L{U(B)g}{b}o(M)B[P.]?{wm(OA20)}()(1)(;j{u}v)k[7nX.]En(pC{X})wK[x()E]Mh(Y)[f]()b[[];:][]A:({7})r[:]3wU[olDn]MB1{}ch[]{PZ([o])}4s{{ivH}}M4[[CM;]IZ][][]af[{}]y{8K}E[Giq[slK]Jwi]{}h{;1I}i(n)[F](fo)8O(cn())[ri]M(9[n]dAV2)[P.D[j]!][][]d{[]}Hk[{b6}hRwi]()BC{l}4()T()nU([!r]C?)GI{S}x()9G[eY4MH,U]G(k8[,T{kU}f]yV){7p{R}}l:(x4){}((F);y)?{j}{t}g{R}Ca{}p{(dN)8R}Sfa[?]e[0]()v{9}([,])Da(3)x{fw[15]},N[[{D[K]9}]b?]?Zf()()U{o{3[()]Nl}J}Wx()BB[{[S]z}]J(yZ0q)x[dq[([])]q]p[[]T]7TE(U[V])bSxd(!Q)I(e8:[H(3)KDo]p){f[u]k}UBe{}(9i(T[S0a])C:).F[:EM[:[SM]a?;]]qI[Q()u]y{}(.()I)L(4)dSB(r){7[]}[[];L][](SP(6d)f)g{.}W()b{3eU}[]6{9}7(J)()(A)mr[p](){()E},()VS(){!U}IA!?{}F7(Z){}[3]{L{m}e72}2u(R()){}4i[rDo],p[2][H6]t.((D))[]uJ[{}t]RV(4{aNqn}q)[7X],q9(0){}F{i}{K}f(a()y){J{0.}WL}6[]Y{O}mHG{{3}86u}h(N{(I)}){}v(Fr)XyEct[;[oL]0]Dp{Xj3}L[][0dH7]g[B(Y;)BOm:]b{}Q{}{y}t(L)z{SG}{{8}}U{h}E[i[]r]{{}}n[D{sJ}:9H]g[]{r}v{bn}j?([]wa){U}e[6]0()Rx[2]C{Ua}!(i)XM[]1;[C!]()q(c2{J{H}s}eQh)1is{sb[o{8}O]H}h{k}[(X)]e{h{V}5}(R)K[]U[H[(B8)x]?]ly{(1()F)}Tp[f([N]U:)][hN4]{D}b{},p(zG{L}e)h(b(9f))()zy{YQ}?M[kq]U2[z9]i(H)Z[]gQ{r}Ik{}fX[k](Yo{O}xN)7k{e}(rS(Uq))([cx])([[]V]H)Rc{(1SZ).l}[[]4e]V{s,{z}}r((o)1f!)xUL()o[t[]]W{(v)jS}o[(1{})Y]g[y]{Qj{}3}7{HH}mK{n}{f}5(t)YB[](C){e}0[{4}]{?}vU{3{Y{U}xX}}LC[y()](y())3i(bPR[6]0)[5](y1Q)p[?][[J]Ey]ZH{S}U(z)Z{qx{VS1{Lz}Yyvy}A}(h)[P]H(oC{})q{};Iq[7]k(7c[F{Bv}Z]?)tG{1G(x)}R(5{D}8)tG{!}P[1]J(hy)0d{r}Z({Wqs};X){}H{S}(L)U(r{K}o6){}D()4?[]H[](![19w]HZ)Z[m][A]2{bDE[J.]uk}[]A[v[]]aJ{}T1[]{3k.[h{?}G]}v{r(.())}(;[tF[JE]])[({}L)4Z]e[K]p{S}J{JMV9{e}x}2()5()h(8){MY[]R;}3[]{o}()b(Px){9}R(A)Ui[]v{J()}{PPh}wC(Wm{Z[s(Y)Of]u}Yg)Q[]{8[j{ux}7];9}B[rup[(YWe)]i0f]CP(ex){}yS(CY)LJ{P[h]f}dD[(q[]z)]3()o[]1[4K()]S{}()3(){{cVa{{j4G}T}aM}0b}[]J(Og)y{h}{5[{60m}]w}mK[p]{}K[usi9(k)B]Ds[]{Ra};{8Q}4{}9m,([])G{;}({S})[7B]L{G}mZ(i())M![]v[u]z(PE5IZ()hw)w()p[JwJ]{[]}((r))H([w[]])k{}T[6.k]{(A)C}XV") << endl;
  cout << areBracketsBalanced("7[G(J0((Ke{{[{Q[J{O({5{(O{B[(;{ob[v,{IY[,x[(5{w{{jT{0(1[M7F{.(aT{[]u}Bm)ze}dI]l4):}p}}R}),]]S}f]W}4)l:];});}}O)}8]}S]I}}M2)LF)C)]:[jS[:{x[(a(x{[0(d([o[{,(gA(((AuE[8{sl[3{{:[u(Q[([Nx[0vqf(pj2{e!{a(WC{;Zb({G((y{j({v[7(o(I?{cth[6I[(6tk{[qu{[g[X{XR{1[(9Hl(g(E(q{z[({({5({QE{o(((n[V{J([,OYY{:m{z(Z{e(yGk(Yh[{{WMb(D(k{s[?{Gr[{.([pt{?E(D[i[{H{[d{4[{1e[{{{[(cC[{s[tc[oRQ{X26{o[[8[z(YQ[[oX9{1h[({(R[[:a7(Y((3T{(B[p;d(J,[({(3T[qU5[Dg[{U[?G(S{Q(v[W([D8({wM[8([X(D(e[A[dt{3K{[qP{A[{(h[:(!g(5J(N:x![MS5(H(({[V{I(!{y.,{w{[U{,JR[aWqu[([(A(3{{Zk:{(X7{g{U{({v(2{(b{cy(3W[v{2(a?7R(a{eJ{jsS(i(R[ZU(gk{{e[0{p([rK{DLB[(z{Kv{s{(Q[c{lI{w[a(e[o([w(bD7(m[L{Q[(a(o(duV[{:{s[t{[bS[{z}B]z],q}KTh]};}]H!)y)FU)]}]s3)re)]R)])N]}!}j])r}}.}y)o]u}w]vIu)!}ouA]e}})c]))E8}E}))y}es]kF)m4})K,u}Q)})}b}}j)z77}T}}M)S)9]q4)b]]r}Y]j}}})}]UV})7)w3)]nH)H))]M)C}]S}]k}a}]z]))]q)]}AS)])])}K)N]}]S]a])}I);C])e2])G}3)IU)k)4]w]p)z9});]}Zh]Is])I]8W9]k,]}G}]qJE]p}k7])]}X.}}dU]:v}1]F!}s]}Q}V]9T]ncX)9,}GW,])raZ}]V};]x}9)PI)J}n}]y)U)W}2)K3W}Ox}X]t)i}i2]gD))z)M}}it!)}5)}O)]G}))4))]ILw}}]]a}]S})XG]5r]}V))kNBR]})4}))}l)}sp)8}ZE}iRL0)B]]:)fu])]}Vnl}M]V4}UqYA]d7)b)N)MS)}S]k]s)N)]bb}u)4n)J]}]w4]i[a]p[8t[{[{s([z(P[Y[D[C[(E[qw{()rp}])]8O]i]]W;G)F])5}rn]B}]]yLX(T4{G{{V3([?ClS[Ha[3(b[[(jr(n({[({;[V:(4[7{{{SU{B[S{Vj[{;[{Y8(e(h(,9{GM{L[[m(h(y{,G[cs[c((([RJ{Z(7K[(a[0(:PS![{M{8(S{(U[W9n{1([[t2({{Ck{77[({R{N{BU(2[z{gQ(i{z[[0CG((ogd[[a((Zx{{a0{{g([Ei{[or[(od[X[p{(2{0{[rh[gZ(J{{xJ{{(Z(a{4,{r([(f{FN0[{N3.(S{F{.{1C([t.{B{(O{((5[b((j{u([{{d(8[TY([E[[{9,f(M([nu[hD{[{{oW92j(fY([r{E{Q(W6{Ox[s8[(8{E{G{{c;i([HG{U{{[(j[Tr:{d8u{([{[[{E7{vmA}}4O]]}]zy)}g}6S])Zsi]}:}}])}}b}Opd}mal0W)r]I]}a)e}cS}fmDz]P))W}j}]W}9]E]T)r)}]FrVS]]W)])kx}}0].),}nk))]);)H9}qw)Jq}P}]RG)5}}}f)U}Z1W]r}U)V])8m}2Y})3)}?}}9})q]]Ly:}I}M)h}9]WQ30]7F)]M3]35e}L]v)Y}}}k})X)vf]]15xh)F)]]}7)k}]2)Ph3FR}k}}s)]}Mi}}G)]])mU}]7)nA})l}w}h]uJ)])]Ck)p}ppvA])E5)s):]]})m)L]]X}M}r)4)g):}]?}2u]}]H}4A}X}}]L)]L}re)8]}xq)u))o]:q]YeE)x]]m])F};Z}7;}:)w([:6(2(wem([(X{u[vj[d2{[Y{g{c[]c7}}!N:]s}]WqV]}m)]IhT))V)R?:])M") << endl;
  cout << areBracketsBalanced("c{v[[c({og(J3([[Mr[3[([(Jz(AT{[5{cNS[([(c({Az[{G{O9c[({D(6[s[r.[({(1(N[b8E{[{Y{;[PX2(jl{{s(p[{W6[w{[U[s67[(?V[sT[{9I[{[({{9((?[8rO[D4[Q[cW[{(({([mN{Q(h{F;[E{J{{{pd{qI[F[fX(k(({RO{j4{4{[3{d[J{9[f9(J{9W{ud[HF({Lz([Q{VN{z[G[!{{X[[!9[[N[({NH{b{[8F[tv((n[f[dBY[p{g[{(c{5jx7[XW{{v[{iT[R{(S{0{{GE[3K(.l(l{NN[l{[{{([{VI1(sGl(z[Vfu{Nba[(l[[k2[!((W(u{D({IZ3((S6(:k{oz1(7{[[(I{[j[(l{Z{({n(wN{(anx(j(N5({M[;Nb{{cw6{1r{Ft[!(C[FF{.{7({{?[H6{sIS{r[o[(x(y[QaAO{[{A42({j(6s[Z{r[8q[[,NX([W(Qd{Q{Y[(S[ZXA{ft{HTj({.(H{c((fD2{[S{z88[Pl{O(WY({w(N(X(b[{(Bd(a(DH(X8c[o{12X{W[X[6T(5Y[F{g[u{((ts4{{{{a[[oY;(7v([(p{h0v5{{(U[9(k(w((A(z[[R[ukn({[((jL{i(b{6Hr[c6:(6(0[[k({f.{{7!([jD{Kd[i{(F[({{e([[{{4(?ryK[g;(iY({G6h{tp{hl.(38F(tzD(eVn(A(V{1Fq(KO7[1[4[c4([[{?(3:[.[DU{R[O(hV{[(1{9[{2A0{Q{Y{Gvq(.q(([(w[{k(,Gi[lGlw{0V4XI{([d[[Y{(E[Z(5C{[A[B[[p(w[Gl{{(t({([H[(rr{X(0Sj(i2[L(d:{YS(Pd[!(z{t(R{;(Y[[[[F[{aZ5{{F[{0[[4rKJ[IC[{{MV(t(T(j{JtM(sX(A((a[io(lv{([w[C[Wd[G{YQ({[(g([v[y{G{J[t{[P([[[t{{(pj{{{S(Z(6{yg[{{(J{{{:eh(((x(qz[[{y{[7![N((([DquG(Y299[V((b{vdi({}WU)})M)Lp9])]?J2)iDe))5]]}XH}M]J]3l)e)))xh}}qCf}TT)}5}C]7}C))t}jUg},})x}}x]]bW]!Rs)]Fm}]}z}]]))]}0J)u}fQ:H]N]]q].)B})4z])y)zp)s)O}7)Y)u)P}5}p.]kX]h],]BdS}]l}}dFN}]]]s]]A)v}l)o}X?)]pv)}2)!]X)m)t})]M:]s)})1)}}D5])xD]ws]]y7]1x}u)q]G)e}o.]67]])}b}]:99)}I]55z)G]V))S6)g}}S}dju}w!B]X}o2)]}T)]q}4z]lD])};]m];)]]H])Q2}R.))k))Jx)L}jSkL}}y,)lE)])}}Acg]]A9)Cz}u})0]0)C}wW]jY}]Dqt)}}Ag}v)]]fb)d)L]p}x)F}c8))]8,})]]]bs))o1)5)M)]5)T};}}AI)W]h))]]o}}.vO}U}k))}V]7}]),]H]gx}}M]A8B)U)y))M}]0))AF)B})3Zb)Ty}:4R]}e]p}))Xv};).})?}}8])wz]}b})]tO)]]F]y}9])})K}LI]}]Z)8)]M]}}.N]}R9}:)}U};]bogf)!]f}V}k}}T]0})R)))})m!})}Q6}3v)g]f]1})1i]a0F4]:})Oo}v))SR)9Hi}74)}0)W)Yi)5]]A])]wL45}]D)3V)W}?])h8}}]O}]}))]N}7}ob}J)P}]}J]xl}s}qWf]!kX})}gO]U}]]Ww]5)B)]7]}}Mb}!)]]e2]]]m}}!],]Mg}l}TY]U)}cA)8GPn]p?}}0)6]9}]1}]1}}7}f})F))]g]}mPH}z9VL}WPrE}Ub}J]}D6y)}]F)}J8W)n;g)W}Vz]]cB0]]:!]9)MLs)yMh}W})S]:}]oH}]])m]J]3]}B3]}As]H)e}})]}ACwK}]}s]8f)wV)NZ}f)]]])}c)w,]o}G}]}2X)Hjcmpu)])k]}]Ch})l)!P])]]i]]w)Y)N:})]lc]l4}cM") << endl;
  cout << areBracketsBalanced("[xZ9k(e)]4[]tx[.hBa]?4{w}3[][kX]ct{}P[h]({(uI)hk2}np)T[ay[]FO].l[ts]:d[T][]l(p){a}g{}Ct0{}{}79(G[YRjB[]]h)[]Vpf{}{}Z{}JmV[m]J{s}Z0oxk(D)HB(JlPs(ScV3)o6AL){}Z[(j6Y(o)S)][h]({,})sG[H[]]nx[9Vc{0}lk]3(w;s)![7lI](W{n});[s]Dc(A)Rz{[]}C(q)R[]z[][S[W]z]()[]{S()tY}[]j{}r[][Vf[]]g{Y}{GT}V{N[WC(.)c]eu}yu(N{C[9c]}2k)q((O)W)jn(I.)NN[r{9WL}jqd]f[HD]{2()}[k]os(!!)Q6{}()t[F]()!6[:]8[NZ{}U]JKM{}Om()ax[,]W{}{F[]G}M6[D:]T[]Wd[j][]R{yV().}(d)()j(M)[J](7),(?()s2sE)y{[n{}F]a}B{}F[yY{6(7)}W]w()t(d)(u)[X[b]7][Eg](25I(x)h)fJM[l]Z[(Q2)X][Ks]{}R[e{Su}s]!(6)h{}aoih[8T][6][5]?{(?(Xo)):}g()G{B{.}8[f(ut()rv)J[n();]C{g5}{}r!l({BK})3[5(;f,P):p]F[Z](1(,g{});)RJ(U)F[Nw]{}vc[lJ]Ly[MVN][U]Wq({T{1}}){}{{Z}}()r{P(b1)s}[NET]{Nv[s3]C}[]W{F}3(7)v[][oI]1[k{3}u1hw]3i(){}J(QjF(1)F)[h{r}B]d{Ul}a(())9{inr}()D(;e)(R())q{A}{}ms[]j()u{}9[nR][!]Zt{PV}5J(b)7{(l:)}T(){BL}x()H{}(U)x{}Y![]Z[t]f[BDEo()9]W{n}T{}{BE[]}q[d2{[I]}jR]1v{PLE!}xlH(O)r{W}p(Zx[O{FF}Wk]q){D{Wp}}[Mp]v({}){}(j){S}u{ZzF}{i}.Q(g)y()A[G]iJ{}(F{]LIs})k8(y)Y0[,Oy[{}]49],t[yT[m]0][;](Ywa)(:1){K}{[ny[]z}[Tc{F}](0({}Gm)j)c{(du)s4}(x)L[K4]5K(;qo)[!]{s5:}qm{Xlu8}{ii{S}}Z[]w9[({})CF(D{}:)C[D{}],IQR{((L)u),}Q[{E.}]H4E(!{[3l]H})pT4[{(x2D)}AO]L[!jG]{{}nf}[]E{}uPj(ot()Z){,{:[]}.}(g(i)Q)()bG()[](4){}[F{gvDz}]J1{ol}P[0[Q]]R()fo{}O{0()}3z[P?]o(J4)G{0}.[l];{E}59X{}u(g4c)fT{g;}()C[!]U[{hOF}Vh]{MoV}Ht()[P{}DG]aa{d}YgWms(Q5)dk[{5g}]3[1XE]q(RG()8n)a[u;],ALC()Q[]p{u}[]Is[]F[3k][y]9{}{Ag}[(P)]{,{p}w}K(8I)b()HLo[]yv[R]bC{Iq{xfI}Ep}![kE]9([6N]W){d[rZ()zhn]W}osu4[{hg?}j]wQ(Le[]Y)?[x]N{}{w}I[]9[]0K(6)(,MY)O({}U)A({}){}o{fC}0[nm]e{I}(2du[])(rp7)z{G}CqA{}f1{}(6f){p[gw[j]C]v}D[i(m)xX]{(Gc)Ox:}{Q}[o]()9U{}7{P}Oi(be)[H]Bh(U)a[o[V[]]Vis]b3{gT}vg{K[0t8]JhW}o([A]1)s{K};[][t][E]V{nA}[{u}]i[H]u{J}({}0ZJ).Gc{}IH{}G{}r[V[h7]f]Z9Q(N8)M!{}{q6[].}(;(a5)E)[v:]{ir}(R)25{ud()R};N[(x)g]TS[t[X]E]Az{[],t}([.j]R1){(F)w}Un1[0](4{O})ql{0}[][]FU{nJ}[].{}{}U[[O]M!I]Hk()Bi{8}{r[]2K}()t()q2n{()G}Ytx{()}GH{T}{}!!R[]c{K}[q(yz)cK]{}[E]{A}J(L3h)8{}[L][6I3]T()x:([W])XHC{z}(6q)[6R][UlA:]({;6})(,[g]l)[??{5x}]HTeP") << endl;
  cout << areBracketsBalanced("{y9{q(([!j[(T{a[CZ[[M[({ZAA[6([g(B]{(3(9{J8y{[x(n(ur(H{J[{(g[e{LPFM(K[!9([iq[:[0L(XX{p{;[(s{O[{[{{({:N]b{[:{({w2(7({K{{{Y{(({{(U0XKr{jz[[q4W(v(((S{EE(([J[lUSi({[9atHv[Avt{.(7{4z[qc{({{(,[gEE({9{O(s[(([[!(n{SUr4[79(x{([(4{L,{y(Pvu{[[4z[(aP{![l[]L]}j)]Mk]]}?)}t}k9J)9]V)u})]}0)]3]EQ)u)H:]E).}}])33])m?F}c})u}]QC}1)}b]:}ZeH)M]]))y?g})C)R4)z)e]]n}D)q}?})EA)}}}}kg}))M})}v]d}}0)H}u}za],}k]}ik)]YT}9}G)]lu].I]6)z])}AA7]G)}Jv]2V}MNq))nv)]6pU3}t};4t))x}8F)Lq]y)]y8}kT)qG]c]bL]]j0}H)]]l))lc}E}{:[(n)E]x3}{{2[Ge?([]2)9T]}}chMq[!l[[1{[F[Bw([PV[j2z(k{Km{{sO{:[V({k[cU(;,W{({(((uV()c.s)))}q)}L)K.]})]F}B}w}iD})B]FC!f]K)]3v]jV}6]]qg{0{z([A{W}])Z}d}{u{{J1}O}M}l{hRr(W{f()}Q)Q4}{c[i{f([(uP[[{![E4d[I[x{a(.(NZ(T{Pul(uy;{}Vi)})4))}VV]d]V]}]Eh]4)y;]v1)}]}s[{N}][H[4T(w(({{[(Q((cjn[7{OtS()J}]))3i)]Z6}?g};u)))]][(j7((z(:(m[{Qd({F[({(C(d(xy{qml[.(?{[;(T{yq((9:(H[I4{{m[oc;(B[Q?[{[{9(GK(l[[(Os[Y(V{E{X(o(D[{[Y[q[vIF((p{[uUt{[kt{.(Re{EYX[{.G{([(((a[{,{In(ZL({9H{q[25{;[[s[[u{bY[(yV(([[{g{Y[zz[V{([eHw(H;{{39U[6q({C[{;(d[(WP(kgYx;{k{lq{LK[(Gm{,[:[!(qKh{(05[(U[r6[3[JZ{f9{c!([(b,{j{(C(3l8[1{wS{X{pW(k[Q{r{7{LQ[({U(k{{b[(k{uE2[Me(SL({pQ(h[!{zF{a[[Z[1M{P{l[s0{(7[(v[({3n([k8({{{(w[[{E(8d[h3(G{[!B[I{t(5n[s[{Tn(!(XmC{({Ig[E(6([[[(5[N[{N{{{P[b(EHn[c[y({M{9K{(K:({[({;(J[m(e4[X{(T(3K{z:{yS{f[7{V7[E{![5[y[{{[[(Q[O!b((W)x)cmt]u)]B]SxuH}p}VP]M]Q]n}]}r]}Z}:n}v)H)XZ}eR]0)6]g)}j)DE]Hb:mQOF}n))Rwy}P!S}7}X4i)V]]Uv)]S}t}J}}g}9HDX],])P]7p]ut])D)]2}o9)}5))}N]]?aA)r}]]u5}1)4o])F}96]]8)F}}o}i)v1]T)}Y)gM])Wi]4)c}E]}p}eAh]oS]5UeQ]tvX}32}4])}Q)aw)]?K}y):47i7]}})E})]Q!e}U:}:TC}d]Gn)6}}t}]y)RA)}z})s])LHR}}kb]e]])cM])t})aU]]}9)t1]xZd}p}A}W))I])zH}W]}KL)Bg]2}H}Y)P2]xX)9}W].H]97}?}Hbz]]))g7Z)dR]}];]]]ha}P]dw}YB}w))}s}]f)x))k]Y)}m}p]az})9}]y}]})aBe)pN]]O]XIA}])y2)}}v)]y)]])ca)}:]y}]3I]n)d]}}])GL))}2)Z]}zw)1]}3QL)B)):WP})b]}H)}xNe]P)33)gM)))4](sK(nZ))rb{3{8[[(0(y!{[l{f{2{(B{7(P[t[a[{{:{!B0k{7[:[g{{F[P[aje({(sp3(?{Njc({H{o(F1K[p{[,[([[p6[[T[S]]]W]]olK)aY]U]RJ}hbt]It)7}}:)5})IY)}V)a]]sr3}td}]]LH?}Qg}V}}cq0]n]HtI]U)r}t)p}c}}Y]}2)1)L].ER]Z}r}") << endl;
	return 0;
}
