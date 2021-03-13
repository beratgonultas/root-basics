void plot()
{
	TFile *file = new TFile("output.root", "READ");

	TH1F *hist1 = (TH1F*)file->Get("hist");

	hist1->Draw();

}
