void style_macro() 
{
	TH1F *hist1 = new TH1F ("hist1", "Histogram", 100, 1, 10);

	TRandom2 *rand = new TRandom2(3);

	fstream file;
	file.open("data_gaus.txt", ios::out);
	
	for(int i=0; i<1000; i++)
	{
		double r = rand->Gaus(5, 1);
		file << r << endl;
	}

	file.close();
	
	file.open("data_gaus.txt", ios::in);
	
	double value;

	while(1)
	{
		file >> value;
		hist1->Fill(value);
		if(file.eof()) break;
	}

	file.close();
	
	hist1->SetFillColor(kGreen-9);
	hist1->GetXaxis()->SetTitle("X Axis");
	hist1->GetYaxis()->SetTitle("Y Axis");
	
	hist1->GetXaxis()->SetTitleSize(0.05);
	hist1->GetYaxis()->SetTitleSize(0.05);
	hist1->GetXaxis()->SetLabelSize(0.05);
	hist1->GetYaxis()->SetLabelSize(0.05);

	TF1 *fit = new TF1("fit", "gaus", 4, 6);

	

	TCanvas *c1 = new TCanvas ();
	c1->SetTickx();
	c1->SetTicky();
	hist1->Draw();
	hist1->Fit("fit", "R");
	//or just
	//hist1->Fit("gauss");

	TLegend *leg = new TLegend(0.7, 0.7,0.9,0.9);
	leg->SetBorderSize(0);
	leg->AddEntry(hist1, "Measured Data", "L");
	leg->AddEntry(fit, "Fit Function", "L");
	leg->Draw();
}
