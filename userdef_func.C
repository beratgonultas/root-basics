void userdef_func()
{
	TCanvas *c1 = new TCanvas();
	TF1 *func = new TF1("func","[0]*cos(x)*exp(-[1]*x)", 0, 10*TMath::Pi());

	func->SetParameter(0, 1);
	func->SetParameter(1, 0.1);

	func->SetTitle("Decaying Cosine Function");

	func->Draw();

}
