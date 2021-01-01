void basic_hist ()
{
	TH1F *hist1 = new TH1F ("hist1", "Histogram", 100, 0, 100);

	hist1->Fill(80);
	hist1->Fill(70);
	hist1->Fill(70);

	hist1->GetXaxis()->SetTitle("X Axis");
	hist1->GetYaxis()->SetTitle("Y Axis");

	TCanvas *c1 = new TCanvas ();
	hist1->Draw();
}
